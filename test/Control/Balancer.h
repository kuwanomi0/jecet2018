#ifndef CONTROL_BALANCER_H
#define CONTROL_BALANCER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"

namespace Control
{
class Balancer
{
private:
	boolean 倒立状態;

	float 目標直進速度;

	float 目標旋回速度;

	ev3api::Motor motor;
	ev3api::Motor motor;

public:
	void 制御する();

};

}  // namespace Control
#endif
