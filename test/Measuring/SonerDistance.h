#ifndef MEASURING_SONER_DISTANCE_H
#define MEASURING_SONER_DISTANCE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/SonarSensor.h"
#include "ev3api/int8_t.h"

namespace measuring
{
class SonerDistance
{
private:
	ev3api::SonarSensor sonarSensor;

public:
	ev3api::int8_t 距離を測る();

};

}  // namespace measuring
#endif
