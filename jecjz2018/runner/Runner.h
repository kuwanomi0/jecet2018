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
    int balanceOn = 0;
    int buttonEnable = 0;
    int sensen = 0;
    int sensenC = 0;

public:
    Runner();
    void exec();
    void start(int forward, int turn, int tailAngle);
    void run(int forward, int turn, int tailAngle);
    void btTask();
    void setPID(float kp, float ki, float kd);
    int getDistance();
    void setBalanceOn(int balanceOn);
    int getBtCmd();
    // void 走る(scenario::シナリオ s);

};
#endif  // RUNNER_RUNNER_H
