#ifndef CONTROL_P_I_D_H
#define CONTROL_P_I_D_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"

namespace Control
{
class PID
{
private:
	float P�l;

	float I�l;

	float D�l;

	ev3api::Motor motor;

public:
	void �v�Z����();

};

}  // namespace Control
#endif
