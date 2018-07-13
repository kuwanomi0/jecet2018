#ifndef MEASURING_IMPACT_SENSOR_H
#define MEASURING_IMPACT_SENSOR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/GyroSensor.h"

namespace measuring
{
class ImpactSensor
{
private:
	ev3api::GyroSensor gyroSensor;

public:
	int 衝撃を検知する();

	void LPF値を取得する();

};

}  // namespace measuring
#endif
