#ifndef MEASURING_COLOR_H
#define MEASURING_COLOR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/rgb_raw_t.h"
#include "ev3api/ColorSensor.h"

namespace measuring
{
class Color
{
private:
	ev3api::rgb_raw_t 前のRGB値;

	double kLPF;

	ev3api::ColorSensor colorSensor;

public:
	ev3api::rgb_raw_t 値を取得する();

	ev3api::rgb_raw_t LPF値を取得する();

	boolean 灰色ですか();

};

}  // namespace measuring
#endif
