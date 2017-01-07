#ifndef MOTORC
#define MOTORC

#define MOTOR_MAX_VALUE 127
#define MOTOR_MIN_VALUE -127
#define slew 5

int motorReq[10];
int motorCur[10];

int forceSetMotor(int port, int power);
int reqMotor(int port, int power);
int setSlew(int port, int slew);

task motorSlewControl() {
	while(true) {
		for(int x = 0; x<10; x++) {
			if(motorReq[x] == motorCur[x]) {
				continue;
			}

			if(motorCur[x] < motorReq[x]) {
				motorCur[x] += slew;
			} else if(motorCur[x] > motorReq[x]) {
				motorCur[x] -= slew;
			}

			forceSetMotor(x, motorCur[x]);
			wait1Msec(LOOPSPEED+LOOPSPEED);
		}
	}
}

int forceSetMotor(int port, int power) {
	motorCur[port] = power;
	if(abs(power) < MOTOR_MAX_VALUE) {
		motor[port+1] = power;
	}
}

int reqMotor(int port, int power, speed) {
	motorReq[port] = power;
}
































#endif
