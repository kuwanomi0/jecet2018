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

#include "Clock.h"

using namespace ev3api;

class RunningTime : public  Clock
{
private:
    // Clock clock;

public:
    RunningTime();
	// int 走行時間を取得する();
	// void 計測開始();
	// void 計測時間を取得する();

};
#endif  // MEASURING_RUNNING_TIME_H
