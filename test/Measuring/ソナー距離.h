#ifndef MEASURING_�\�i�[����_H
#define MEASURING_�\�i�[����_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/SonarSensor.h"
#include "ev3api/int8_t.h"

namespace Measuring
{
class �\�i�[����
{
private:
	ev3api::SonarSensor sonarSensor;

public:
	ev3api::int8_t �����𑪂�();

};

}  // namespace Measuring
#endif
