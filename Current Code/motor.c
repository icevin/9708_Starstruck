#ifndef MOTORC
#define MOTORC

#define MOTOR_MAX_VALUE 127
#define MOTOR_MIN_VALUE -127
#define slew 10


int armReq;
int armCur;



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

void reqArm(int power) {
	armReq = power;
}

#endif
