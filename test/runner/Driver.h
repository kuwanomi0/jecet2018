/**
 ******************************************************************************
 ** ファイル名 : Driver.h
 ** クラス名   : Driver
 **
 ** 概要 : 走行体に指示するクラス
 ******************************************************************************
 **/
#ifndef RUNNER_DRIVER_H
#define RUNNER_DRIVER_H

#include "Runner.h"
// #include "scenario/シナリオ.h"

class Driver
{
private:
    int testc = 0;
    Runner* runner;
    // scenario::シナリオ senarios[];
    // scenario::シナリオ シナリオ;

public:
    Driver();
    void start();
    void exec();
    void bt_task();
    // void 区間を渡す();

};
#endif  // RUNNER_DRIVER_H
