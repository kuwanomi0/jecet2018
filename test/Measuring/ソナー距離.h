#ifndef MEASURING_ソナー距離_H
#define MEASURING_ソナー距離_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/SonarSensor.h"
#include "ev3api/int8_t.h"

namespace Measuring
{
class ソナー距離
{
private:
	ev3api::SonarSensor sonarSensor;

public:
	ev3api::int8_t 距離を測る();

};

}  // namespace Measuring
#endif
