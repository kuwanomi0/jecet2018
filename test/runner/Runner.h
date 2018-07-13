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

#include "scenario/シナリオ.h"
#include "measuring/InstrumentPanel.h"

class Runner
{
private:
    measuring::InstrumentPanel m;

public:
    void 走る(scenario::シナリオ s);

};
#endif  // RUNNER_RUNNER_H
