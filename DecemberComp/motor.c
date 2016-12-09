#ifndef MOTORC
#define MOTORC

int motorReq[10];
int motorCur[10];

bool motorChange = 0;

int forceSetMotor(int port, int power);
int reqMotor(int port, int power);
int setSlew(int port, int slew);

int forceSetMotor(int port, int power) {
	motorCur[port-1] = power;
	motor[port] = power;
}

int reqMotor(int port, int power, speed) {
	motorReq[port-1] = power;
}
































#endif