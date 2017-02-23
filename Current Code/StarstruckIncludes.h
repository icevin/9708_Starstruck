#ifndef FUNCTIONS
#define FUNCTIONS

//MOVEMENT FUNCTIONS














//LEGACY FUNCTIONS
task OpenClaw() {
	//NEGATIVE IS OPEN

	//NEGATIVE MOTOR POWER = POSITIVE POT VALUE = OPEN

	//POSITIVE IS CLOSE

	while(SensorValue(potL) > 2300 || SensorValue(potL) < 1900 || SensorValue(potR) > 2300 || SensorValue(potR) < 1900)
	{
		if(SensorValue(potL) > 2300)
		{
			motor[clawL] = 70;
		}

		if(SensorValue(potL) < 1900) {
			motor[clawL] = -70;

		}

		if(SensorValue(potR) > 2300)
		{
			motor[clawR] = 70;
		}

		if(SensorValue(potR) < 1900) {
			motor[clawR] = -70;
		}

		if(SensorValue(potL) < 2300 && SensorValue(potL) > 1900) {
			motor[clawL] = 0;
		}

		if(SensorValue(potR) < 2300 && SensorValue(potR) > 1900) {
			motor[clawR] = 0;
		}
		wait1Msec(LOOPSPEED);
	}

	motor[clawL] = 0;
	motor[clawR] = 0;
}

void halfOpenClaw() {
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
}

void armRotationUser(int r) {
	int counter=0;
	while(SensorValue(armEncoder) < r-24 || SensorValue(armEncoder) > r+24)
	{

		if(SensorValue(armEncoder) < r-24)
		{
			motor[armL1] = -50;
			motor[armL2] = -50;
			motor[armR1] = -50;
			motor[armR2] = -50;
			wait1Msec(50);
		}
		else if(SensorValue(armEncoder) > r+24)
		{
			motor[armL1] = 50;
			motor[armL2] = 50;
			motor[armR1] = 50;
			motor[armR2] = 50;

			wait1Msec(50);
		}
		if (counter>=r-40)
		{
			motor[clawR] = 20;
			motor[clawL]=20;
			wait1Msec(50);
		}
		counter+=1;
	}
}

void armRotation(int r) {
	int counter=0;
	while(SensorValue(armEncoder) < r-24 || SensorValue(armEncoder) > r+24)
	{

		if(SensorValue(armEncoder) < r-24)
		{
			motor[armL1] = -50;
			motor[armL2] = -50;
			motor[armR1] = -50;
			motor[armR2] = -50;
			wait1Msec(500);
		}

		if(SensorValue(armEncoder) > r+24)
		{
			motor[armL1] = 50;
			motor[armL2] = 50;
			motor[armR1] = 50;
			motor[armR2] = 50;

			wait1Msec(500);
		}
		counter+=1;

	}
}


#endif
