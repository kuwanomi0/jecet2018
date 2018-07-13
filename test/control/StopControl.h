#ifndef CONTROL_STOP_CONTROL_H
#define CONTROL_STOP_CONTROL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"

namespace control
{
class StopControl
{
private:
	ev3api::Motor motor;
	ev3api::Motor motor;

public:
	void 停止する();

};

}  // namespace control
#endif
