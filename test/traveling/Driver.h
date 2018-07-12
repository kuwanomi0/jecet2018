#ifndef TRAVELING ODY_DRIVER_H
#define TRAVELING ODY_DRIVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Scenario/シナリオ.h"

namespace  Traveling ody
{
class Driver
{
private:
	Scenario::シナリオ senarios[];

	Scenario::シナリオ シナリオ;

public:
	void 区間を渡す();

};

}  // namespace  Traveling ody
#endif
