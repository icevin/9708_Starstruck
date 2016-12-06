#pragma config(Motor,  port2,           driveLeftBack, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           driveLeftFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           arm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           driveRightBack, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           driveRightFront, tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify

//CONSTANTS
#define LOOPSPEED 50 //Time between user control loops in milliseconds - time alloted to other tasks while usercontrol is idle
#define DEADZONE 20 //Deadzone for joystick control

//VARIABLES
float powerExpanderBatteryV;

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
	// Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.

	bStopTasksBetweenModes = true;
}

task autonomous()
{
	//autonSelector();
}


task usercontrol()
{
	//Control variables
	int dlC, drC, armC;
	while(true){
		dlC = vexRT[Ch3];
		drC = vexRT[Ch2];
		armC = vexRT[Ch3Xmtr2];

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

		if(abs(armC) > DEADZONE)	{
			motor[arm] = armC;
		}
		else {
			motor[arm] = 0;
		}
		// Displays Battery Levels to VEX Remote Screen
		powerExpanderBatteryV = SensorValue[in1]/.28;
		clearLCDLine(0);
		clearLCDLine(1);
		displayLCDPos(0,0);
		displayNextLCDString("C Bat:");
		displayNextLCDNumber(nAvgBatteryLevel);
		displayLCDPos(1,0);
		displayNextLCDString("P.E Bat:");
		displayNextLCDNumber(powerExpanderBatteryV);

		//Graphing for PID tuning
		/*
		datalogDataGroupStart();
		datalogAddValue(0, VAR1);
		datalogAddValue(1, VAR2);
		datalogAddValue(2, VAR3);
		datalogAddValue(3, VAR4);
		datalogDataGroupEnd();
		*/
		wait1Msec(LOOPSPEED);
	}
}
