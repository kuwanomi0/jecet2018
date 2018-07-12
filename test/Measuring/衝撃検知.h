#ifndef MEASURING_衝撃検知_H
#define MEASURING_衝撃検知_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/GyroSensor.h"

namespace Measuring
{
class 衝撃検知
{
private:
	ev3api::GyroSensor gyroSensor;

public:
	int 衝撃を検知する();

	void LPF値を取得する();

};

}  // namespace Measuring
#endif
