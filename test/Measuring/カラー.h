#ifndef MEASURING_�J���[_H
#define MEASURING_�J���[_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "RGB.h"
#include "ev3api/ColorSensor.h"

namespace Measuring
{
class �J���[
{
private:
	RGB �O��RGB�l;

	double kLPF;

	ev3api::ColorSensor colorSensor;

public:
	RGB �l���擾����();

	RGB LPF�l���擾����();

	boolean �D�F�ł���();

};

}  // namespace Measuring
#endif
