#ifndef MEASURING_START_TASK_H
#define MEASURING_START_TASK_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/BluetoothTask.h"

namespace Measuring
{
class StartTask
{
private:
	ev3api::BluetoothTask bluetoothTask;

public:
	void スタートさせる();

};

}  // namespace Measuring
#endif
