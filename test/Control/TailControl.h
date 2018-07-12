#ifndef CONTROL_TAIL_CONTROL_H
#define CONTROL_TAIL_CONTROL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"
#include "Control/PID.h"

namespace Control
{
class TailControl
{
private:
	int 目標角;

	ev3api::Motor motor;
	PID pID;

public:
	/**
	 * 
	 * 
	 */
	void 設定する(int 目標角);

	void 制御する();

};

}  // namespace Control
#endif
