#ifndef RUNNER_DRIVER_H
#define RUNNER_DRIVER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "scenario/シナリオ.h"

namespace runner
{
class Driver
{
private:
	scenario::シナリオ senarios[];

	scenario::シナリオ シナリオ;

public:
	void 区間を渡す();

};

}  // namespace runner
#endif
