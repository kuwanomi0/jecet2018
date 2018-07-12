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
	float P値;

	float I値;

	float D値;

	ev3api::Motor motor;

public:
	void 計算する();

};

}  // namespace Control
#endif
