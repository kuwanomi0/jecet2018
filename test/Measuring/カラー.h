#ifndef MEASURING_カラー_H
#define MEASURING_カラー_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "RGB.h"
#include "ev3api/ColorSensor.h"

namespace Measuring
{
class カラー
{
private:
	RGB 前のRGB値;

	double kLPF;

	ev3api::ColorSensor colorSensor;

public:
	RGB 値を取得する();

	RGB LPF値を取得する();

	boolean 灰色ですか();

};

}  // namespace Measuring
#endif
