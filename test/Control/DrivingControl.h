#ifndef CONTROL_DRIVING_CONTROL_H
#define CONTROL_DRIVING_CONTROL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"
#include "Control/PID.h"

namespace Control
{
class DrivingControl
{
private:
	ev3api::Motor motor;
	PID pID;

public:
	void ëñçsÇ∑ÇÈ();

};

}  // namespace Control
#endif
