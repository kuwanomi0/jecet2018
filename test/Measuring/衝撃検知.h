#ifndef MEASURING_�Ռ����m_H
#define MEASURING_�Ռ����m_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/GyroSensor.h"

namespace Measuring
{
class �Ռ����m
{
private:
	ev3api::GyroSensor gyroSensor;

public:
	int �Ռ������m����();

	void LPF�l���擾����();

};

}  // namespace Measuring
#endif
