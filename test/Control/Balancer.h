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
	boolean �|�����;

	float �ڕW���i���x;

	float �ڕW���񑬓x;

	ev3api::Motor motor;
	ev3api::Motor motor;

public:
	void ���䂷��();

};

}  // namespace Control
#endif
