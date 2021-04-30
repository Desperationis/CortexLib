#include "Controllers.h"

/*
  Task handle to the current_controller; This is automatically managered
  internally in here.
*/
TaskHandle current_controller = NULL;
ubyte control_delay = 20;


void control_set_delay(ubyte delay) {
  control_delay = delay;
}

void control_stop() {
  if(current_controller != NULL) {
    if(taskGetState(current_controller) == TASK_RUNNING) {
      taskDelete(current_controller);
    }
  }
}

void control_switch(void(*task_code)(void)) {
  control_stop();
  current_controller = taskRunLoop(task_code, 20);
}

void control_xdrivecorner() {
  int x = joystickGetAnalog(1, 4);
	int y = joystickGetAnalog(1, 3);
  int theta = joystickGetAnalog(1, 1);

  slew_set(XDC_TOPLEFT, motor_cap(y + x + theta));
  slew_set(XDC_TOPRIGHT, motor_cap(-y + x + theta));
  slew_set(XDC_BOTTOMLEFT, motor_cap(y - x + theta));
  slew_set(XDC_BOTTOMRIGHT, motor_cap(-y - x + theta));
}

void control_xdrivecorner_gamer() {
	int y = joystickGetAnalog(1, 3);
  int theta = joystickGetAnalog(1, 1);

  slew_set(XDC_TOPLEFT, motor_cap(y + theta));
  slew_set(XDC_TOPRIGHT, motor_cap(-y + theta));
  slew_set(XDC_BOTTOMLEFT, motor_cap(y + theta));
  slew_set(XDC_BOTTOMRIGHT, motor_cap(-y + theta));
}

void control_xdriveedge() {
	int x = joystickGetAnalog(1, 4);
	int y = joystickGetAnalog(1, 3);
  int delta = joystickGetAnalog(1, 1);

  slew_set(XDR_LEFT, motor_cap(y + delta));
  slew_set(XDR_RIGHT, motor_cap(-y + delta));
  slew_set(XDR_UP, motor_cap(x + delta));
  slew_set(XDR_DOWN, motor_cap(-x + delta));
}
