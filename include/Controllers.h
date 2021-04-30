#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <API.h>
#include "Motor.h"
#include "Slew.h"

/*
  Configure chassis motors here; The value of each enum represents the motor
  port. The functions that use these options follow the same format:

  control_{name} -> enum {NAME}_PORTS

  Some may follow this format, though it's basically the same:

  control_{name}_{moreinfo} -> enum {NAME}_{PORTS}

  Feel free to change the order of enums, if you need to.
*/
enum XDRIVECORNER_PORTS {XDC_BOTTOMLEFT = 1, XDC_TOPRIGHT, XDC_TOPLEFT, XDC_BOTTOMRIGHT = 10};
enum XDRIVEEDGE_PORTS {XDR_LEFT = 1, XDR_RIGHT, XDR_UP, XDR_DOWN = 10};

/*
Safely switches to another controller. If a controller is not currently
running, this starts one. The thread handle for this is managed internally.
*/
void control_switch(void(*task_code)(void));

/*
	Sets the delay of all controllers; By default, this is set to 20. Lowering it
  won't do you any good.
*/
void control_set_delay(ubyte delay);

/*
	Stops the task for the current controller.
*/
void control_stop();

/*
	Control chassis via an xdrive configuration where the corners are the wheels.
	Left joystick is for movement, right for turning. This assumes that, when all
	motors are powered with a positive value via the Motor module, the robot turns
  clockwise.
*/
void control_xdrivecorner();

/*
  Control chassis via an xdrive configuration where the corners are the wheels.
  Left joystick is for forward / backward, right for turning; Kind of like a
  racing game. This assumes that, when all motors are powered with a positive
  value via the Motor module, the robot turns clockwise.
*/
void control_xdrivecorner_gamer();


/*
	Control chassis via an xdrive configuration where the edges are the wheels;
	The "front" of the robot is a wheel. Left joystick is for movement, right for
	turning. This assumes that, when all motors are powered with a positive value
	 via the Motor module, the robot turns clockwise.
*/
void control_xdriveedge();


#endif
