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
    int style = 0;
    int lookupLine = 0;
    int lookupLineC = 0;
    int seesawLine = 0;
    int distanceTmp = 0;

public:
    Runner();
    void start(int forward, int turn, int tailAngle);
    void run(int forward, int turn, int tailAngle, float krgb);
    void btUpdate();
    int getDistance();
    int getGyroImpact();
    int getSonarDis();
    int getBtCmd();
    void setPID(float kp, float ki, float kd);
    void setStyle(int style);
    void setGyroOffset(int gyroOffset);
    void stop();
};
#endif  // RUNNER_RUNNER_H
