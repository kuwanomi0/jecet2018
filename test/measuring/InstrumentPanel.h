#ifndef MEASURING_INSTRUMENT_PANEL_H
#define MEASURING_INSTRUMENT_PANEL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "measuring/RunningDistance.h"
#include "measuring/Color.h"
#include "measuring/ImpactSensor.h"
#include "measuring/SonerDistance.h"
#include "measuring/RunningTime.h"

namespace measuring
{
class InstrumentPanel
{
private:
	RunningDistance distance;

	Color color;

	ImpactSensor impact;

	SonerDistance sonar;

	RunningTime time;

	Color color;
};

}  // namespace measuring
#endif
