/**
 ******************************************************************************
 ** ファイル名 : Runner.h
 ** クラス名   : Runner
 **
 ** 概要 : 走行を管理するクラス
 ******************************************************************************
 **/
#ifndef RUNNER_RUNNER_H
#define RUNNER_RUNNER_H

// #include "scenario/シナリオ.h"
#include "ev3api.h"
#include "../control/ControlManager.h"
#include "../measuring/InstrumentPanel.h"

class Runner
{
private:
    ControlManager* cm;
    InstrumentPanel* inspanel;

public:
    Runner();
    void exec();
    void start(int forward, int turn, int tail);
    void run(int forward, int turn, int tail);
    void bt_task();
    // void 走る(scenario::シナリオ s);

};
#endif  // RUNNER_RUNNER_H
