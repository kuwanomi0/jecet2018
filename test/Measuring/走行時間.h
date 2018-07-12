#ifndef MEASURING_走行時間_H
#define MEASURING_走行時間_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Clock.h"

namespace Measuring
{
class 走行時間
{
private:
	int 計測開始時間;

	ev3api::Clock clock;

public:
	int 走行時間を取得する();

	void 計測開始();

	void 計測時間を取得する();

};

}  // namespace Measuring
#endif
