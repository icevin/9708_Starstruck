#ifndef FUNCTIONS
#define FUNCTIONS

#define Ka 0.5


void rotate(float angle, int power);
float getAngle();
int checkAngle(int target);
int inRange(int value, int min, int max);
int notInRange(int value, int min, int max);
void moveTime(int angle, int time, int power);
void setDriveMotors(int forwardVector, int rotationVector, int horizontalVector);
void setArm(int armPower);
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
 88, 89, 89, 90, 90, 127, 127, 127
};

void waitUntilDetectChange(){
	int initial = SensorValue(clawUltrasonic);
	while(abs(initial-SensorValue(clawUltrasonic)) < 4) {
			wait1Msec(100);
	}
	return;
}

void cycle() {		///ASSUMING STARTING FROM FENCE, LIFT DOWN, CLAW OPEN: moves forward, closes claw, moves back, dumps
	moveTime(0, 1000, 60);
	motor[clawL] = 60;
	motor[clawR] = 60;
	moveTime(180, 500, 60);
	setArm(120);
	wait1Msec(1200);
	motor[clawL] = -60;
	motor[clawR] = -60;
	setArm(0);
	setDriveMotors(0, 0, 0);
	motor[clawL] = 0;
	motor[clawR] = 0;

}

int clamp(int x) {
	if(x>127) {
		x = 127;
	} else if(x< -127) {
		x = -127;
	}
	return x;
}

int trueSpeed(int x) {
	int value = linearizeSpeed[clamp(abs(x))];
	if(x>=0)
		return value;
	else if(x<0)
		return -value;
	else
		return 0;
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

void setArm(int armPower) {
	motor[armL1] = armPower;
	motor[armL2] = armPower;
	motor[armR1] = armPower;
	motor[armR2] = armPower;
}

void moveTime(int angle, int time, int power) { //angle in degrees, time in ms
	//Calculate motor values
	float forwardV = cosDegrees(angle) * power;
	float horizonV = sinDegrees(angle) * power;

	int forPower = forwardV;
	int horPower = horizonV;
	setDriveMotors(forPower, 0, horPower);
	wait1Msec(time);
	setDriveMotors(0, 0, 0);
}

void rotateTime(int power, int time) {
	setDriveMotors(0, power, 0);
	wait1Msec(time);
	setDriveMotors(0, 0, 0);
}

void setDriveMotors(int forwardVector, int rotationVector, int horizontalVector) {
	int LF, RF, LB, RB;
	LF = forwardVector + rotationVector + horizontalVector;
	RF = forwardVector - rotationVector - horizontalVector;
	LB = forwardVector + rotationVector - horizontalVector;
	RB = forwardVector - rotationVector + horizontalVector;

	if(abs(LF) > DEADZONE)
		motor[dLeftF] = trueSpeed(clamp(LF));
	else
		motor[dLeftF] = 0;
	if(abs(RF) > DEADZONE)
		motor[dRightF] = trueSpeed(clamp(RF));
	else
		motor[dRightF] = 0;
	if(abs(LB) > DEADZONE)
		motor[dLeftB] = trueSpeed(clamp(LB));
	else
		motor[dLeftB] = 0;
	if(abs(RB) > DEADZONE)
		motor[dRightB] = trueSpeed(clamp(RB));
	else
		motor[dRightB] = 0;
}

















//BROKEN FUNCTIONS (NO DRIVE ENCODERS)

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

void rotate(float angle, int power) {

	/* pseudocode


	while(notInRange(getAngle, angle, 20)) {

		power = (angle - getAngle()) * some constant; <---- simple P controller
		motors = checkAngle * power
		wait1Msec(50);
	}

	*/
}

void move(int angle, int amount, int power) { //angle in degrees
	//Calculate motor values
	int forwardV = sinDegrees(angle) * power;
	int horizonV = cosDegrees(angle) * power;
	//while loop for moving & amount
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
