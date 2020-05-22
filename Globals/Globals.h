#ifndef GLOBALS_HEADER
#pragma systemFile
#define GLOBALS_HEADER

/*
 * Globals.h
 *
 * Setter / Getter System for global variables and structs.
 * Used for avoiding the use of extern.
 *
*/

typedef struct {
	double kP;
	double kI;
	double kD;
	short proportion;
	short integral;
	short derivative;
	short pastError;
} PIDInfo;


// Setters
void SetLeftMotor(tMotor port);                      					                       // Sets the left motor port
void SetRightMotor(tMotor port);                                                     // Sets the right motor port
void SetLeftEncoder(tSensors port);                                                  // Sets the left encoder port
void SetRightEncoder(tSensors port);                                                 // Sets the right encoder port
void SetControllerSpeed(double speed);                                               // Sets the controller speed of the robot's wheels
void SetAverageDelay(ubyte delayTime);                                               // Sets the delay of all tasks
void SetSlewStep(ubyte step);                                                        // Sets the step amount for slew controller

// Getters
tMotor GetLeftMotor();                                                               // Gets the left motor port
tMotor GetRightMotor();                                                              // Gets the right motor port
tSensors GetLeftEncoder();                                                           // Gets the left encoder port
tSensors GetRightEncoder();                                                          // Gets the right encoder port
ubyte GetDelay();                                                                    // Gets the delay of all tasks
ubyte GetSlewStep();                                                                 // Gets the step amount of slew controller
double GetControllerSpeed();                                                         // Gets the controller speed

#endif
