/**
 ******************************************************************************
 ** ファイル名 : RunningTime.h
 ** クラス名   : RunningTime
 **
 ** 概要 : 走行時間の計算を行うクラス
 ******************************************************************************
 **/
#ifndef MEASURING_RUNNING_TIME_H
#define MEASURING_RUNNING_TIME_H

#include "ev3api/Clock.h"

class RunningTime
{
private:
	int 計測開始時間;
	ev3api::Clock clock;

public:
	int 走行時間を取得する();
	void 計測開始();
	void 計測時間を取得する();

};
#endif  // MEASURING_RUNNING_TIME_H
