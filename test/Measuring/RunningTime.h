#ifndef MEASURING_RUNNING_TIME_H
#define MEASURING_RUNNING_TIME_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Clock.h"

namespace measuring
{
class RunningTime
{
private:
	int 計測開始時間;

	ev3api::Clock clock;

public:
	int 走行時間を取得する();

	void 計測開始();

	void 計測時間を取得する();

};

}  // namespace measuring
#endif
