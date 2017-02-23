#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    potL,           sensorPotentiometer)
#pragma config(Sensor, in2,    potR,           sensorPotentiometer)
#pragma config(Sensor, dgtl1,  armEncoder,     sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  armButton,      sensorNone)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           clawL,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           dLeftF,        tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port3,           dLeftB,        tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port4,           armL1,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           armL2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           armR1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armR2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           dRightF,       tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port9,           dRightB,       tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port10,          clawR,         tmotorVex393_HBridge, openLoop)
#pragma platform(VEX)
#pragma competitionControl(Competition)


/* NOTES
Potentiometer key:
Closed: ~3900
180 Degrees: ~2660
45 degrees (facing towards stars but not closed): ~1700
Fully closed: ~1000, 1100
*/


#define LOOPSPEED 50 //Time between user control loops in milliseconds - time alloted to other tasks while usercontrol is idle
#define DEADZONE 30 //Deadzone for joystick control
#define m_clawL 1
#define m_dLeftF 2
#define m_dLeftB 3
#define m_armL1 4
#define m_armL2 5
#define m_armR1 6
#define m_armR2 7
#define m_dRightF 8
#define m_dRightB 9
#define m_clawR 10

//ENCODER TICKS PER REVOLUTION
#define TURBOM          261.333
#define SPEEDM          392
#define TORQUM          627.2
#define QUAD          360.0

#define joy_left_vertical "Ch3Xmtr2"
#define joy_left_horizontal "Ch4Xmtr2"
#define joy_right_vertical "Ch2Xmtr2"
#define joy_right_horizontal "Ch1Xmtr2"

#define ROTATION_REDUCTION 0.75

#define PID_MAX 120
#define PID_MIN -120
#define PID_INTEGRAL_LIMIT 40
#define PID_POLL_RATE 100 //Milliseconds between PID controller updates

#define CLAW_FULL_CLOSED 1100
#define CLAW_HALF_CLOSED 1700
#define CLAW_180 2660
#define CLAW-STOWED 3800

//GLOBAL VARIABLES
float powerExpanderBatteryV;
//Control variables
int armC, armUp, armDown, openClaw, closeClaw;
int armMotors;
int clawRequest;



#include "Vex_Competition_Includes.c"


#include "StarstruckIncludes.h"
#include "motor.c"
#include "auton.h"





void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.

	bStopTasksBetweenModes = true;
}

task autonomous()
{
	//kevAuton();
	//driveAuton();
	newKevAuton();
	//TODO: potentiometer auton selector
}

int forwardVector, horizontalVector, rotationVector;
task control() {
	nSchedulePriority = 10;

	//Math variables
	int mReqLF, mReqRF, mReqLB, mReqRB, clawValue;
	while(true){

		armC = vexRT[Ch2Xmtr2];
		openClaw = vexRT[Btn6UXmtr2] * 120;
		closeClaw = vexRT[Btn6DXmtr2] * -120;


		armUp = vexRT[Btn5UXmtr2];
		armDown = vexRT[Btn5DXmtr2];



		forwardVector = vexRT[Ch3Xmtr2];
		horizontalVector = vexRT[Ch4Xmtr2];
		rotationVector = vexRT[Ch1Xmtr2] * 0.5;

		mReqLF = forwardVector + rotationVector + horizontalVector;
		mReqRF = forwardVector - rotationVector - horizontalVector;
		mReqLB = forwardVector + rotationVector - horizontalVector;
		mReqRB = forwardVector - rotationVector + horizontalVector;

		if(abs(mReqLF) > DEADZONE)
			motor[dLeftF] = linearizeSpeed[mReqLF];
		else
			motor[dLeftF] = 0;

		if(abs(mReqRF) > DEADZONE)
			motor[dRightF] = linearizeSpeed[mReqRF];
		else
			motor[dRightF] = 0;

		if(abs(mReqLB) > DEADZONE)
			motor[dLeftB] = linearizeSpeed[mReqLB];
		else
			motor[dLeftB] = 0;

		if(abs(mReqRB) > DEADZONE)
			motor[dRightB] = linearizeSpeed[mReqRB];
		else
			motor[dRightB] = 0;


		if(SensorValue(armButton) == 1) {
			SensorValue(armEncoder) = 0;
		}


		if(armUp==1)
		{
			armMotors=120;
		}

		else if((armDown==1))
		{
			armMotors=-120;
		}
		else
		{
			armMotors=0;
		}



		clawValue = openClaw + closeClaw;
		motor[clawL] = clawValue;
		motor[clawR] = clawValue;

		//Set Motors
		reqArm(armMotors);

		//Displays Battery Levels to VEX Remote Screen
		powerExpanderBatteryV = SensorValue[in1]/.28;
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDPos(0,0);
		displayNextLCDString("C Bat:");
		displayNextLCDNumber(nAvgBatteryLevel);
		displayLCDPos(1,0);
		displayNextLCDString("P.E Bat:");
		displayNextLCDNumber(powerExpanderBatteryV);


		if(vexRT[Btn7UXmtr2] == 1)
		{
			startTask(OpenClaw);
		}


		datalogDataGroupStart();
		datalogAddValue(0, armMotors);
		datalogAddValue(1, clawValue);

		datalogAddValue(2, mReqLF);
		datalogAddValue(3, mReqRF);
		datalogAddValue(4, mReqLB);
		datalogAddValue(5, mReqRB);
		datalogDataGroupEnd();

		wait1Msec(LOOPSPEED);
	}
}

task usercontrol()
{
	startTask(control);
	startTask(armSlewControl);
}
