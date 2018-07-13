#ifndef CONTROL_DRIVING_CONTROL_H
#define CONTROL_DRIVING_CONTROL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"
#include "control/PID.h"

namespace control
{
class DrivingControl
{
private:
	ev3api::Motor motor;
	PID pID;
	ev3api::Motor motor;
	ev3api::Motor motor;

public:
	void 走行する();

};

}  // namespace control
#endif
