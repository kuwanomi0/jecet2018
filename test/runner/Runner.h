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
    void start();
    // void 走る(scenario::シナリオ s);

};
#endif  // RUNNER_RUNNER_H
