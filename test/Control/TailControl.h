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
	int ñ⁄ïWäp;

	ev3api::Motor motor;
	PID pID;

public:
	/**
	 * 
	 * 
	 */
	void ê›íËÇ∑ÇÈ(int ñ⁄ïWäp);

	void êßå‰Ç∑ÇÈ();

};

}  // namespace Control
#endif
