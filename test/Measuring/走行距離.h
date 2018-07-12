#ifndef MEASURING_走行距離_H
#define MEASURING_走行距離_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"
#include "ev3api/int8_t.h"

namespace Measuring
{
class 走行距離
{
private:
	int 計測開始距離;

	ev3api::Motor motor;

private:
	void 走行距離を計算する();

public:
	ev3api::int8_t 走行距離を取得する();

	void 計測開始();

	int 計測距離を取得する();

};

}  // namespace Measuring
#endif
