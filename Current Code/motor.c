//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#ifndef MOTORC
#define MOTORC

#define MOTOR_MAX_VALUE 127
#define MOTOR_MIN_VALUE -127
#define slew 10


int armReq;
int armCur;

void setArm(int armPower);

task armSlewControl() {
	int diff = 0;
	while(true) {
			diff = armReq - armCur;
			
			
			//Add/subtract ArmCur
			if(armCur < armReq) {
				armCur += (0.4*abs(diff));
			} else if(armCur > armReq) {
				armCur -= (0.4*abs(diff));
			}

			
			//Set arm motors to ArmCur
			if(armReq == 0) {
				setArm(0);
			} else if(abs(armCur) < MOTOR_MAX_VALUE) {
				if(armCur > 100) {
					setArm(120);
				} else {
					setArm(armCur);
				}
			}
			wait1Msec(LOOPSPEED*3);
	}
}

void setArm(int armPower) {
	motor[armL1] = armPower;
	motor[armL2] = armPower;
	motor[armR1] = armPower;
	motor[armR2] = armPower;
}

void reqArm(int power) {
	armReq = power;
}

int clawReq = 0, clawState = 0;

task clawControl() {
	//PID VARIABLES
	float pid_Kp = 0.01;
	float pid_Ki = 0.0;
	float pid_Kd = 0.0;

	float pidError;
	float pidLastError;
	float pidIntegral;
	float pidDerivative;

	float pidDrive;
	int clawPot;
	pidLastError = 0;
	pidIntegral = 0;

	while (true)
	{
		clawPot = SensorValue(potL);
		pidError = clawPot - clawReq;

		if(pid_Ki!=0) {
			if(fabs(pidError) < PID_INTEGRAL_LIMIT)
				pidIntegral = pidIntegral + pidError;
			else
				pidIntegral = 0;
		} else {
			pidIntegral = 0;
		}
		if(pidError !=0) {
			pidDerivative = pidError - pidLastError;
			pidLastError = pidError;
		} else {
			pidDerivative = 0;
		}
		if(pidError < 40.0)
			pidIntegral = 0;


		pidDrive = (pid_Kp*pidError) + (pid_Ki*pidIntegral) + (pid_Kd * pidDerivative);

		if(pidDrive > PID_MAX)
			pidDrive = PID_MAX;
		if(pidDrive < PID_MIN)
			pidDrive = PID_MIN;

		wait1Msec(100);
	}
}


/*
#define MOTOR_MAX_VALUE 127
#define MOTOR_MIN_VALUE -127
#define slew 10


int armReq;
int armCur;

void setArm(int armPower);

task armSlewControl() {
	int diff = 0;
	while(true) {
			diff = armReq - armCur;

			if(armCur < armReq) {
				armCur += (0.7*abs(diff));
			} else if(armCur > armReq) {
				armCur -= (0.7*abs(diff));
			}

			if(armReq == 0) {
				setArm(0);
			} else if(abs(armCur) < MOTOR_MAX_VALUE) {
				if(armCur > 90) {
					setArm(120);
				} else {
					setArm(armCur);
				}
			}
			wait1Msec(LOOPSPEED*3);
	}
}

void setArm(int armPower) {
	motor[armL1] = armPower;
	motor[armL2] = armPower;
	motor[armR1] = armPower;
	motor[armR2] = armPower;
}

void reqArm(int power) {
	armReq = power;
}

int clawReq = 0, clawState = 0;
/*
task clawControl() {
	//PID VARIABLES
	float pid_Kp = 0.01;
	float pid_Ki = 0.0;
	float pid_Kd = 0.0;

	float pidError;
	float pidLastError;
	float pidIntegral;
	float pidDerivative;

	float pidDrive;
	int clawPot;
	pidLastError = 0;
	pidIntegral = 0;

	while (true)
	{
		clawPot = SensorValue(pot);
		pidError = clawPot - clawReq;

		if(pid_Ki!=0) {
			if(fabs(pidError) < PID_INTEGRAL_LIMIT)
				pidIntegral = pidIntegral + pidError;
			else
				pidIntegral = 0;
		} else {
			pidIntegral = 0;
		}
		if(pidError !=0) {
			pidDerivative = pidError - pidLastError;
			pidLastError = pidError;
		} else {
			pidDerivative = 0;
		}
		if(pidError < 40.0)
			pidIntegral = 0;


		pidDrive = (pid_Kp*pidError) + (pid_Ki*pidIntegral) + (pid_Kd * pidDerivative);

		if(pidDrive > PID_MAX)
			pidDrive = PID_MAX;
		if(pidDrive < PID_MIN)
			pidDrive = PID_MIN;

		wait1Msec(100);
	}
}
*/
#endif
