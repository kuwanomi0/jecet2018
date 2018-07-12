#ifndef MEASURING_計測盤_H
#define MEASURING_計測盤_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Measuring/走行距離.h"
#include "Measuring/カラー.h"
#include "Measuring/衝撃検知.h"
#include "Measuring/ソナー距離.h"
#include "Measuring/走行時間.h"

namespace Measuring
{
class 計測盤
{
private:
	走行距離 distance;

	カラー color;

	衝撃検知 impact;

	ソナー距離 sonar;

	走行時間 time;

	カラー カラー;
};

}  // namespace Measuring
#endif
