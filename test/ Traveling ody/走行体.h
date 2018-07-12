#ifndef TRAVELING ODY_走行体_H
#define TRAVELING ODY_走行体_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Scenario/シナリオ.h"
#include "Measuring/計測盤.h"

namespace  Traveling ody
{
class 走行体
{
private:
	Measuring::計測盤 m;


public:
	void 走る(Scenario::シナリオ s);

};

}  // namespace  Traveling ody
#endif
