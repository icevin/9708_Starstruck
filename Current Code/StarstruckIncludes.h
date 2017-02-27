#ifndef FUNCTIONS
#define FUNCTIONS

#define Ka 0.5


void rotate(float angle, int power);
float getAngle();
int checkAngle(int target);
int inRange(int value, int min, int max);
int notInRange(int value, int min, int max);
int move(int angle, int amount, int power);
void setDriveMotors(int forwardVector, int rotationVector, int horizontalVector);
//MOVEMENT FUNCTIONS

const unsigned int linearizeSpeed[128] =
{
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, 21, 21, 21, 22, 22, 22, 23, 24, 24,
 25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
 28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
 33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
 37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
 41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
 46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
 52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
 61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
 71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
 80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
 88, 89, 89, 90, 90,127,127,127
};

int clamp(int x) {
	if(x>127) {
		x = 127;
	} else if(x< -127) {
		x = -127;
	}
	return x;
}

int trueSpeed(int x) {
	int value = linearizeSpeed[abs(x)];
	if(x>0)
		return value;
	else if(x<0)
		return -value;
	else
		return 0;


}

void rotate(float angle, int power) {

	/* pseudocode


	while(notInRange(getAngle, angle, 20)) {

		power = (angle - getAngle()) * some constant; <---- simple P controller
		motors = checkAngle * power
		wait1Msec(50);
	}

	*/
}

int inRange(int value, int min, int max) {
	if( value > max || value < min)
		return 0;
	else
		return 1;
}

int notInRange(int value, int min, int max) {
	if( value > max || value < min)
		return 1;
	else
		return 0;
}

int checkAngle(int target) {
	int tAngle = getAngle();
	if (tAngle > target)
		return 1;
	else if (tAngle < target)
		return -1;
	else
		return 0;
}

float getAngle() {
//dLeftF
//dRightF
//dLeftB
//dRightB
	int offsetL, offsetR;

	//"y=x" diagonal
	offsetR = (nMotorEncoder[dRightF] - nMotorEncoder[dLeftB]);

	//"y=-x" diagonal
	offsetL = (nMotorEncoder[dLeftF] - nMotorEncoder[dRightB]);

	//Need testing to convert offset into angle

	return Ka * (offsetL+offsetR) / 2;
}




int move(int angle, int amount, int power) { //angle in degrees

	//Calculate motor values
	int forwardV = sinDegrees(angle) * power;
	int horizonV = cosDegrees(angle) * power;
	//while loop for moving & amount

}



void setDriveMotors(int forwardVector, int rotationVector, int horizontalVector) {
	/*
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
		*/
}


























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
