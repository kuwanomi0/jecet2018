/**
 ******************************************************************************
 ** ファイル名 : TailControl.h
 ** クラス名   : TailControl
 **
 ** 概要 : 尻尾制御を行うクラス
 ******************************************************************************
 **/
#ifndef CONTROL_TAIL_CONTROL_H
#define CONTROL_TAIL_CONTROL_H

#include "ev3api/Motor.h"
#include "control/PID.h"

class TailControl
{
private:
    int 目標角;
    ev3api::Motor motor;
    PID pID;
    ev3api::Motor motor;

public:
    void 設定する(int 目標角);
    void 制御する();

};
#endif  // CONTROL_TAIL_CONTROL_H
