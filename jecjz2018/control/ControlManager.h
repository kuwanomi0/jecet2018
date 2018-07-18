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
#include "PID.h"

class ControlManager
{
private:
    Balancer* balancer;
    MotorControl* mc;
    TailControl* tc;
    PID* motorPid;

public:
    ControlManager();
    void tailInit();
    void wheelInit();
    void balancerInit();
    void running(int forward, int turn, int tailAngle);
    void running(int forward, int turn, int tailAngle, int32_t gyro, int volt, int totalRGB);
    void stop();
    void setPID(float kp, float ki, float kd);
};
#endif  // CONTROL_CONTROL_MANAGER_H
