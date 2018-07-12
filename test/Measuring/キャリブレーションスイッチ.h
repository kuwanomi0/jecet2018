#ifndef MEASURING_キャリブレーションスイッチ_H
#define MEASURING_キャリブレーションスイッチ_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/TouchSensor.h"

namespace Measuring
{
class キャリブレーションスイッチ
{
private:
	ev3api::TouchSensor touchSensor;

public:
	bool 値を取得();

};

}  // namespace Measuring
#endif
