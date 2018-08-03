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
    int lookupLine = 0;
    int lookupLineC = 0;
    int distanceTmp = 0;

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
    void lookupRun(int* forward, int* turn, int* tailAngle);

};
#endif  // RUNNER_RUNNER_H
