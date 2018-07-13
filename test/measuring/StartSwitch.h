#ifndef MEASURING_START_SWITCH_H
#define MEASURING_START_SWITCH_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/TouchSensor.h"
#include "ev3api/BluetoothTask.h"

namespace measuring
{
class StartSwitch
{
private:
	ev3api::TouchSensor touchSensor;
	ev3api::TouchSensor touchSensor;
	ev3api::BluetoothTask bluetoothTask;

public:
	bool 値を取得();

};

}  // namespace measuring
#endif
