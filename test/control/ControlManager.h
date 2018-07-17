/**
 ******************************************************************************
 ** ファイル名 : ControlManager.h
 ** クラス名   : ControlManager
 **
 ** 概要 : 制御を管理するクラス
 ******************************************************************************
 **/
#ifndef CONTROL_CONTROL_MANAGER_H
#define CONTROL_CONTROL_MANAGER_H

#include "BalancerCpp.h"
#include "MotorControl.h"
#include "TailControl.h"

class ControlManager
{
private:
    Balancer* balancer;
    MotorControl* mc;
    TailControl* tc;

public:
    ControlManager();
    void tailInit();
    void wheelInit();
    void balancerInit();
    void running(int forward, int turn, int angle);
};
#endif  // CONTROL_CONTROL_MANAGER_H
