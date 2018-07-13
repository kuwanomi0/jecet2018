/**
 ******************************************************************************
 ** ファイル名 : StopControl.h
 ** クラス名   : StopControl
 **
 ** 概要 : 停止制御を行うクラス
 ******************************************************************************
 **/
#ifndef CONTROL_STOP_CONTROL_H
#define CONTROL_STOP_CONTROL_H

#include "ev3api/Motor.h"

class StopControl
{
private:
    ev3api::Motor motor;
    ev3api::Motor motor;

public:
    void 停止する();

};
#endif  // CONTROL_STOP_CONTROL_H
