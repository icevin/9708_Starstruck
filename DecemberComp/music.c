#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    potCL,          sensorPotentiometer)
#pragma config(Sensor, in2,    potCR,          sensorPotentiometer)
#pragma config(Sensor, dgtl1,  touchSensL,     sensorTouch)
#pragma config(Sensor, dgtl2,  touchSensR,     sensorTouch)
#pragma config(Sensor, dgtl6,  quadL,          sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  quadR,          sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           clawL,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           driveLeftBack, tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port3,           driveLeftFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           armL1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           armL2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           armR1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armR2,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           driveRightBack, tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port9,           driveRightFront, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          clawR,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)


//GLOBAL VARIABLES
float powerExpanderBatteryV;
//Control variables
int dlC, drC, armC, forwardsC, backwardsC, musicCtrl;
int armMotors;

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify
#include "music.h"
#include "Starstruck.h"
#include "motor.c"

//CONSTANTS
#define LOOPSPEED 50 //Time between user control loops in milliseconds - time alloted to other tasks while usercontrol is idle
#define DEADZONE 20 //Deadzone for joystick control

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.

	bStopTasksBetweenModes = true;
}

task autonomous()
{
	wait1Msec(2500);
}

task nonMusic() {
	nSchedulePriority = 10;
	//Math variables
	int lastArmC, currArmC;
	
	while(true){
		
		joyLV = vexRT[Ch3];
		joyLH = vexRT[Ch4];
		joyRV = vexRT[Ch2];
		joyRH = vexRT[Ch1];
		
		armC = vexRT[Ch2Xmtr2];
		forwardsC = vexRT[Btn7U];
		backwardsC = vexRT[Btn7D];

		musicCtrl = vexRT[Btn7UXmtr2];

		
		if(abs(dlC) > DEADZONE)	{
			motor[driveLeftBack] = dlC;
			motor[driveLeftFront] = dlC;
		}
		else {
			motor[driveLeftBack] = 0;
			motor[driveLeftFront] = 0;
		}
		if(abs(drC) > DEADZONE)	{
			motor[driveRightBack] = drC;
			motor[driveRightFront] = drC;
		}
		else {
			motor[driveRightBack] = 0;
			motor[driveRightFront] = 0;
		}

		lastArmC = currArmC;
		currArmC = armC;
		
		if(abs(armC) > DEADZONE) {
			armMotors = armC;
			} else {
			armMotors = 0;
		}

		
		
		
		
		
		//Set Motors
		motor[armL1] = armMotors;
		motor[armL2] = armMotors;
		motor[armR1] = armMotors;
		motor[armR2] = armMotors;
		
		
		
		
		
		
		
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

		wait1Msec(LOOPSPEED);
	}
}

unsigned int beat = 0;

task music()
{
	nSchedulePriority = 8;
	while(true) {
		if(musicCtrl == 1) {

			if(beat <= 70) {
				playImmediateTone(intro[beat][0],(intro[beat][1]-3));
				wait1Msec(intro[beat][1] * 10);
			} else if(beat <= 227) {
				playImmediateTone(beforeRepeat[beat-71][0], (beforeRepeat[beat-71][1]-3));
				wait1Msec(beforeRepeat[beat-71][1] * 10);
			} else if(beat <= 316) {
				playImmediateTone(chorus1[beat-228][0], (chorus1[beat-228][1]-3));
				wait1Msec(chorus1[beat-228][1] * 10);
			} else if(beat <= 474) {
				if(beat == 317) {
					playImmediateTone(0, 64.171);
					wait1Msec(641.71);
				}
				playImmediateTone(beforeRepeat[beat-318][0], (beforeRepeat[beat-318][1]-3));
				wait1Msec(beforeRepeat[beat-318][1] * 10);
			} else if(beat <= 562) {
				playImmediateTone(chorus2[beat-475][0], (chorus2[beat-475][1]-3));
				wait1Msec(chorus2[beat-475][1] * 10);
			} else if(beat <= 719) {
				if(beat == 563) {
					playImmediateTone(0, 64.171);
					wait1Msec(641.71);
				}
				playImmediateTone(beforeRepeat[beat-563][0], (beforeRepeat[beat-563][1]-3));
				wait1Msec(beforeRepeat[beat-563][1] * 10);
			}

			//Beat advancing and repeat
			beat++;
			if(beat > 719) {
				beat = 0;
			}
		}	else {wait1Msec(1000);}
	}
}


task motorSlewRate() {

}

task usercontrol()
{
	startTask(music);
	startTask(nonMusic);
	startTask(motorSlew);
}