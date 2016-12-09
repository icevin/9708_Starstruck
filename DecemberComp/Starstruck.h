#ifndef FUNCTIONS
#define FUNCTIONS




//GLOBAL VARIABLES
float powerExpanderBatteryV;
//Control variables
int dlC, drC, armC, knockC, forwardsC, backwardsC, touchSensLC, touchSensRC;
float armMultiplier, dMult = 1;

void clearEncoders() {
	//nMotorEncoder[driveLeftBack] = 0;
	//nMotorEncoder[driveRightBack] = 0;
}

void drive(int encoderCounts, int speed)
{
	clearEncoders();
	//While both of the encoders are less than the specified amount
	while(abs(nMotorEncoder[driveLeftwBack]) < abs(encoderCounts))
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[driveRightBack]) == abs(nMotorEncoder[driveLeftBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveLeftBack] = speed;
			motor[driveLeftFront] = speed;
			motor[driveRightBack] = speed;
			motor[driveRightFront] = speed;

		}
		if(abs(nMotorEncoder[driveRightBack]) < abs(nMotorEncoder[driveLeftBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveRightBack] = speed;
			motor[driveRightFront] = speed;
			motor[driveLeftBack] = speed+10;
			motor[driveLeftFront] = speed+10;
		}
		else if(abs(nMotorEncoder[driveRightBack]) > abs(nMotorEncoder[driveLeftBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveRightBack] = speed+10;
			motor[driveRightFront] = speed+10;
			motor[driveLeftBack] = speed;
			motor[driveLeftFront] = speed;
		}
	}
	//Stop the robot
			motor[driveRightBack] = 0;
			motor[driveRightFront] = 0;
			motor[driveLeftBack] = 0;
			motor[driveLeftFront] = 0;
}

//Turn the robot left for the specified encoder counts
//at a specified speed
void turnLeft(int encoderCounts, int speed)
{
	//Clear the encoders before using them
	clearEncoders();
	//While the absolute value of the right motor's encoder is less
	//than the specified amount
	while(abs(nMotorEncoder[driveLeftBack]) < encoderCounts)
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[driveLeftBack]) == abs(nMotorEncoder[driveLeftBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveLeftBack] = -speed;
			motor[driveLeftFront] = -speed;
			motor[driveRightBack] = speed;
			motor[driveRightFront] = speed;

		}
		if(abs(nMotorEncoder[driveLeftBack]) < abs(nMotorEncoder[driveRightBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveLeftBack] = -(speed+10);
			motor[driveLeftFront] = -(speed+10);
			motor[driveRightBack] = speed;
			motor[driveRightFront] = speed;

		motor[driveRightBack] = speed;
			motor[driveLeftBack] = -(speed+10);

		}
		else if(abs(nMotorEncoder[driveLeftBack]) > abs(nMotorEncoder[driveRightBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveRightBack] = speed+10;
			motor[driveLeftBack] = -speed;

		}
	}
	//Stop the robot
	motor[driveRightBack] = 0;
	motor[driveLeftBack] = 0;
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
	while(abs(nMotorEncoder[driveRightBack]) < encoderCounts)
	{
		//If the two encoder values are equal
		if(abs(nMotorEncoder[driveRightBack]) == abs(nMotorEncoder[driveLeftBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveRightBack] = -speed;
			motor[driveLeftBack] = speed;

		}
		if(abs(nMotorEncoder[driveRightBack]) < abs(nMotorEncoder[driveLeftBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveRightBack] = -speed;
			motor[driveLeftBack] = speed+10;

		}
		else if(abs(nMotorEncoder[driveRightBack]) > abs(nMotorEncoder[driveLeftBack]))
		{
			//Move the robot forward at the specified speed
			motor[driveRightBack] = -(speed+10);
			motor[driveLeftBack] = speed;

		}
	}
	//Stop the robot
	motor[driveRightBack] = 0;
	motor[driveLeftBack] = 0;
}


#endif
