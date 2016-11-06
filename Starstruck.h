#ifndef FUNCTIONS
#define FUNCTIONS


//GLOBAL VARIABLES
float powerExpanderBatteryV;
//Control variables
int dlC, drC, armC, knockC, forwardsC, backwardsC;
float armMultiplier, dMult = 1;


void clearEncoders() {
	nMotorEncoder[driveLeft1] = 0;
	nMotorEncoder[driveRight1] = 0;
}

void drive(int encoderCounts, int speed)
{
	clearEncoders();
	//While both of the encoders are less than the specified amount
	while(abs(nMotorEncoder[driveRight1]) < abs(encoderCounts))
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[driveRight1]) == abs(nMotorEncoder[driveLeft1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = speed;
			motor[driveLeft1] = speed;

		}
		if(abs(nMotorEncoder[driveRight1]) < abs(nMotorEncoder[driveLeft1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = speed;
			motor[driveLeft1] = speed+10;

		}
		else if(abs(nMotorEncoder[driveRight1]) > abs(nMotorEncoder[driveLeft1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = speed+10;
			motor[driveLeft1] = speed;

		}
	}
	//Stop the robot
	motor[driveRight1] = 0;
	motor[driveLeft1] = 0;
}

//Turn the robot left for the specified encoder counts
//at a specified speed
void turnLeft(int encoderCounts, int speed)
{
	//Clear the encoders before using them
	clearEncoders();
	//While the absolute value of the right motor's encoder is less
	//than the specified amount
	while(abs(nMotorEncoder[driveLeft1]) < encoderCounts)
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[driveLeft1]) == abs(nMotorEncoder[driveLeft1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = speed;
			motor[driveLeft1] = -speed;

		}
		if(abs(nMotorEncoder[driveLeft1]) < abs(nMotorEncoder[driveRight1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = speed;
			motor[driveLeft1] = -(speed+10);

		}
		else if(abs(nMotorEncoder[driveLeft1]) > abs(nMotorEncoder[driveRight1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = speed+10;
			motor[driveLeft1] = -speed;

		}
	}
	//Stop the robot
	motor[driveRight1] = 0;
	motor[driveLeft1] = 0;
}

//Turn the robot left for the specified encoder counts
//at a specified speed
void turnRight(int encoderCounts, int speed)
{

	//Clear the encoders
	clearEncoders();

	//While the absolute value of the left motor's encoder is less
	//than the specified amount

	//Turn the robot to the right at the specified speed
	while(abs(nMotorEncoder[driveRight1]) < encoderCounts)
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[driveRight1]) == abs(nMotorEncoder[driveLeft1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = -speed;
			motor[driveLeft1] = speed;

		}
		if(abs(nMotorEncoder[driveRight1]) < abs(nMotorEncoder[driveLeft1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = -speed;
			motor[driveLeft1] = speed+10;

		}
		else if(abs(nMotorEncoder[driveRight1]) > abs(nMotorEncoder[driveLeft1]))
		{
			//Move the robot forward at the specified speed
			motor[driveRight1] = -(speed+10);
			motor[driveLeft1] = speed;

		}
	}
	//Stop the robot
	motor[driveRight1] = 0;
	motor[driveLeft1] = 0;
}
