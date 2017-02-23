#ifndef AUTON
#define AUTON

void newKevAuton() {
	motor[clawL] = -90;
	motor[clawR] = -90;
	wait1Msec(1500);
	motor[clawL] = 0;
	motor[clawR] = 0;

	motor[dLeftF] = 70;
	motor[dRightF] = 70;
	motor[dLeftB] = 70;
	motor[dRightB] = 70;
	wait1Msec(700);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[dLeftF] = -40;
	motor[dRightF] = 40;
	motor[dLeftB] = -40;
	motor[dRightB] = 40;
	wait1Msec(600);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	motor[dLeftF] = 60;
	motor[dRightF] = 60;
	motor[dLeftB] = 60;
	motor[dRightB] = 60;
	wait1Msec(700);
	motor[clawL] = 50;
	motor[clawR] = 50;
	wait1Msec(300);
	motor[dLeftF] = 0;
	motor[dRightF] = 0;
	motor[dLeftB] = 0;
	motor[dRightB] = 0;

	wait1Msec(1000);
	motor[dLeftF] = -85;
	motor[dRightF] = 85;
	motor[dLeftB] = -85;
	motor[dRightB] = 85;

	wait1Msec(900);
	motor[dLeftF] = -70;
	motor[dRightF] = -70;
	motor[dLeftB] = -70;
	motor[dRightB] = -70;
	wait1Msec(500);

	motor[dLeftF] = -70;
	motor[dRightF] = -70;
	motor[dLeftB] = -70;
	motor[dRightB] = -70;
	wait1Msec(800);
	motor[armL1] = 110;
	motor[armL2] = 110;
	motor[armR1] = 110;
	motor[armR2] = 110;
	wait1Msec(1200);
	motor[clawL] = -90;
	motor[clawR] = -90;
	wait1Msec(300);
	motor[armL1] = 0;
	motor[armL2] = 0;
	motor[armR1] = 0;
	motor[armR2] = 0;
	motor[clawL] = 0;
	motor[clawR] = 0;
	wait1Msec(2000);
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
