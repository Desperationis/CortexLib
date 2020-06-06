#pragma systemFile
#ifndef GLOBALS_SOURCE
#define GLOBALS_SOURCE
#include "Globals.h"


// Globals
tMotor leftMotorPort;
tSensors leftEncoderPort;
tMotor rightMotorPort;
tSensors rightEncoderPort;

ubyte taskDelay;
float controllerSpeed;


// Setters
void SetLeftMotor(tMotor port) {
	leftMotorPort = port;
}

void SetRightMotor(tMotor port) {
	rightMotorPort = port;
}

void SetLeftEncoder(tSensors port) {
	leftEncoderPort = port;
}

void SetRightEncoder(tSensors port) {
	rightEncoderPort = port;
}

void SetControllerSpeed(float speed) {
	if(speed <= 1) {
		controllerSpeed = speed;
	}
}

void SetAverageDelay(ubyte delayTime) {
	taskDelay = delayTime;
}

// Getters
tMotor GetLeftMotor(){
	return leftMotorPort;
}

tMotor GetRightMotor(){
	return rightMotorPort;
}

tSensors GetLeftEncoder(){
	return leftEncoderPort;
}

tSensors GetRightEncoder(){
	return rightEncoderPort;
}

ubyte GetDelay() {
	return taskDelay;
}

double GetControllerSpeed(){
	return controllerSpeed;
}

#endif
