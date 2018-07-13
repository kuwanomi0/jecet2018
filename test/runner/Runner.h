#ifndef RUNNER_RUNNER_H
#define RUNNER_RUNNER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "scenario/シナリオ.h"
#include "measuring/InstrumentPanel.h"

namespace runner
{
class Runner
{
private:
	measuring::InstrumentPanel m;


public:
	void 走る(scenario::シナリオ s);

};

}  // namespace runner
#endif
