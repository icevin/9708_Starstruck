#ifndef AUTON
#define AUTON

void newNewAuton() {

	motor[clawL] = -90;		//OPEN CLAW
	motor[clawR] = -90;
while (abs(SensorValue(potL) - CLAW_FULL_CLOSED) < 500)
{
	wait1Msec(10);			//WAIT UNTIL OPEN
}
	motor[clawL] = 0;			//STOP CLAW
	motor[clawR] = 0;

	motor[dLeftF] = 70;		//DRIVE FORWARDS
	motor[dRightF] = 70;
	motor[dLeftB] = 70;
	motor[dRightB] = 70;
	wait1Msec(700);				//DRIVE FOR 700MS
	motor[dLeftF] = 0;		//STOP
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[dLeftF] = -40;	//START ROTATION
	motor[dRightF] = 40;
	motor[dLeftB] = -40;
	motor[dRightB] = 40;
	wait1Msec(600);				//ROTATE FOR 600MS
	motor[dLeftF] = 0;		//STOP ROTATION
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[dLeftF] = 60;		//DRIVE FORWARDS
	motor[dRightF] = 60;
	motor[dLeftB] = 60;
	motor[dRightB] = 60;
	wait1Msec(700);				//WAIT 700MS
	motor[clawL] = 50;		//START CLOSING CLAW
	motor[clawR] = 50;
	wait1Msec(300);				//WAIT 300MS
	motor[dLeftF] = 0;		//STOP DRIVING
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	wait1Msec(1000);		//WAIT FOR CLAW TO CLOSE/SECURE
	motor[dLeftF] = -85;	//ROTATE AGAIN
	motor[dRightF] = 85;
	motor[dLeftB] = -85;
	motor[dRightB] = 85;

	wait1Msec(900);
	motor[dLeftF] = -90;	//START MOVING BACKWARDS
	motor[dRightF] = -90;
	motor[dLeftB] = -90;
	motor[dRightB] = -90;

	wait1Msec(800);			//WAIT 800MS
	motor[armL1] = 120;		//START DUMPING (still moving backwards)
	motor[armL2] = 120;
	motor[armR1] = 120;
	motor[armR2] = 120;
	wait1Msec(1300);		//WAIT UNTIL AT PEAK OF DUMP
	motor[clawL] = -90;	//START OPENING CLAW
	motor[clawR] = -90;
	wait1Msec(300);
	motor[armL1] = 0;
	motor[armL2] = 0;
	motor[armR1] = 0;
	motor[armR2] = 0;
	motor[clawL] = 0;
	motor[clawR] = 0;
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;
}

void newKevAuton() {
	motor[clawL] = -60;		//OPEN CLAW
	motor[clawR] = -60;
	wait1Msec(1350);			//WAIT UNTIL OPEN
	motor[clawL] = 0;			//STOP CLAW
	motor[clawR] = 0;

	wait1Msec(100);
	setArm(-50);
	wait1Msec(400);
	setArm(0);

	motor[dLeftF] = 80;		//DRIVE FORWARDS
	motor[dRightF] = 80;
	motor[dLeftB] = 80;
	motor[dRightB] = 80;
	wait1Msec(800);				//DRIVE FOR 700MS
	motor[dLeftF] = 0;		//STOP
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[dLeftF] = -50;	//START ROTATION
	motor[dRightF] = 50;
	motor[dLeftB] = -50;
	motor[dRightB] = 50;
	wait1Msec(500);				//ROTATE FOR 600MS
	motor[dLeftF] = 0;		//STOP ROTATION
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;
	wait1Msec(100);
	setArm(-50);
	wait1Msec(400);
	setArm(0);

	motor[dLeftF] = 60;		//DRIVE FORWARDS
	motor[dRightF] = 60;
	motor[dLeftB] = 60;
	motor[dRightB] = 60;
	wait1Msec(800);				//WAIT 700MS
	motor[clawL] = 70;		//START CLOSING CLAW
	motor[clawR] = 70;
	wait1Msec(300);				//WAIT 300MS
	motor[dLeftF] = 0;		//STOP DRIVING
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	wait1Msec(800);		//WAIT FOR CLAW TO CLOSE/SECURE
	motor[dLeftF] = -115;	//ROTATE AGAIN
	motor[dRightF] = 115;
	motor[dLeftB] = -115;
	motor[dRightB] = 115;

	wait1Msec(900);
	motor[dLeftF] = -100;	//START MOVING BACKWARDS
	motor[dRightF] = -100;
	motor[dLeftB] = -100;
	motor[dRightB] = -100;

	wait1Msec(700);			//WAIT 800MS
	motor[armL1] = 120;		//START DUMPING (still moving backwards)
	motor[armL2] = 120;
	motor[armR1] = 120;
	motor[armR2] = 120;
//while (SensorValue(armEncoder) > -500)
//{
//	wait1Msec(10);		//WAIT UNTIL AT PEAK OF DUMP
//}
//	motor[clawL] = -90;	//START OPENING CLAW
//	motor[clawR] = -90;
//while (abs(SensorValue(potL) - CLAW_FULL_CLOSED) < 500)
//{
//	wait1Msec(10);			//WAIT UNTIL OPEN
//}
	wait1Msec(1000);
		motor[clawL] = -90;	//START OPENING CLAW
		motor[clawR] = -90;
	wait1Msec(600);
	motor[armL1] = 0;
	motor[armL2] = 0;
	motor[armR1] = 0;
	motor[armR2] = 0;
	motor[clawL] = 0;
	motor[clawR] = 0;
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;
}


//LEGACY AUTONS

void auton1() {
	motor[clawR] = 70;
	motor[clawL]= 70;
	wait1Msec(1500);
	motor[clawR] = 0;
	motor[clawL] = 0;

	motor[armL1] = 100;
	motor[armL2] = 100;
	motor[armR1] = 100;
	motor[armR2] = 100;
	wait1Msec(2000);
	motor[armL1] = 0;
	motor[armL2] = 0;
	motor[armR1] = 0;
	motor[armR2] = 0;

	motor[dLeftB] = 70;
	motor[dRightB] = 70;
	motor[dLeftF] = 70;
	motor[dRightF] = 70;
	wait1Msec(1700);
	motor[dLeftB] = 0;
	motor[dRightB] = 0;
	motor[dLeftF] = 0;
	motor[dRightF] = 0;

	motor[dLeftB] = -50;
	wait1Msec(200);
	motor[dRightB] = 50;
	wait1Msec(200);
	motor[dLeftF] = 50;
	wait1Msec(200);
	motor[dRightF] = 50;
	wait1Msec(5000);
//	halfOpenClaw();
	armRotation(-256);

	motor[dLeftB] = 0;
	motor[dRightB] = 0;
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[clawL] = 0;
	motor[clawR] = 0;
	motor[armL1] = 0;
	motor[armL2] = 0;
	motor[armR1] = 0;
	motor[armR2] = 0;
}

void auton2() {
motor[dLeftB] = 70;
motor[dRightB] = 70;
motor[dLeftF] = 70;
motor[dRightF] = 70;
wait1Msec(3000);
motor[dLeftB] = 0;
motor[dRightB] = 0;
motor[dLeftF] = 0;
motor[dRightF] = 0;
}

void auton3(){

	//halfOpenClaw();
	motor[clawL] = 0;
	motor[clawR] = 0;
	armRotation(-256);

	motor[dLeftB] = -50;
	motor[dRightB] = 50;
	motor[dLeftF] = 50;
	motor[dRightF] = -50;
	wait1Msec(2500);



	motor[dLeftB] = 0;
	motor[dRightB] = 0;
	motor[dLeftF] = 0;
	motor[dRightF] = 0;

	motor[armL1] = 0;
	motor[armL2] = 0;
	motor[armR1] = 0;
	motor[armR2] = 0;


	while(SensorValue(potL) < 2500 || SensorValue(potL) > 2800)
	{
		if(SensorValue(potL) < 2500)
		{
			motor[clawL] = -50;
			motor[clawR] = -50;
			wait1Msec(50);
		}
		if(SensorValue(potL) > 2800)
		{
			motor[clawL] = 50;
			motor[clawR] = 50;
			wait1Msec(50);
		}
	}
	wait1Msec(200);

	while(SensorValue(potL) < 2500 || SensorValue(potL) > 2800)
	{
		if(SensorValue(potL) < 2500)
		{
			motor[clawL] = -50;
			motor[clawR] = -50;
			wait1Msec(50);
		}
		if(SensorValue(potL) > 2800)
		{
			motor[clawL] = 50;
			motor[clawR] = 50;
			wait1Msec(50);
		}
	}
	motor[clawL] = 0;
	motor[clawR] = 0;


	motor[dLeftB] = 80;
	motor[dRightB] = -80;
	motor[dLeftF] = 80;
	motor[dRightF] = -80;
	wait1Msec(2000);


	motor[dLeftB] = 0;
	motor[dRightB] = 0;
	motor[dLeftF] = 0;
	motor[dRightF] = 0;

}

void auton7() {
	//kevAuton();
	motor[armL1]=-110;
	motor[armL2]=-110;
	motor[armR1]=-110;
	motor[armR2]=-110;
	wait1Msec(300);
	motor[armL1]=0;
	motor[armL2]=0;
	motor[armR1]=0;
	motor[armR2]=0;
}

void driveAuton() {
	motor[dLeftF] = 120;
	motor[dRightF] = 120;
	motor[dLeftB] = 120;
	motor[dRightB] = 120;
	wait1Msec(3500);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;
}

void kevAuton() {
	//halfOpenClaw();
	motor[clawL] = -90;
	motor[clawR] = -90;
	wait1Msec(1500);
	motor[clawL] = 0;
	motor[clawR] = 0;

	motor[dLeftF] = 120;
	motor[dRightF] = 120;
	motor[dLeftB] = 120;
	motor[dRightB] = 120;
	wait1Msec(2000);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;
	//close claw function

	motor[dLeftF] = -90;
	motor[dRightF] = 90;
	motor[dLeftB] = -90;
	motor[dRightB] = 90;
	wait1Msec(1000);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[dLeftF] = 120;
	motor[dRightF] = 120;
	motor[dLeftB] = -120;
	motor[dRightB] = 120;
	wait1Msec(1000);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[clawL] = 90;
	motor[clawR] = 90;
	wait1Msec(1500);
	motor[clawL] = 50;
	motor[clawR] = 50;

	motor[dLeftF] = -90;
	motor[dRightF] = 90;
	motor[dLeftB] = -90;
	motor[dRightB] = 90;
	wait1Msec(2000);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[dLeftF] = -120;
	motor[dRightF] = -120;
	motor[dLeftB] = -120;
	motor[dRightB] = -120;
	wait1Msec(1200);

	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[armL1] = 110;
	motor[armL2] = 110;
	motor[armR1] = 110;
	motor[armR2] = 110;
	wait1Msec(1300);
	motor[clawL] = -90;
	motor[clawR] = -90;
	wait1Msec(300);
	motor[armL1] = 0;
	motor[armL2] = 0;
	motor[armR1] = 0;
	motor[armR2] = 0;
	motor[clawL] = 0;
	motor[clawR] = 0;

}

#endif
