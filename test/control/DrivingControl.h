/**
 ******************************************************************************
 ** ファイル名 : DrivingControl.h
 ** クラス名   : DrivingControl
 **
 ** 概要 : 走行制御を行うクラス
 ******************************************************************************
 **/
#ifndef CONTROL_DRIVING_CONTROL_H
#define CONTROL_DRIVING_CONTROL_H

#include "ev3api/Motor.h"
#include "control/PID.h"

class DrivingControl
{
private:
    ev3api::Motor motor;
    PID pID;
    ev3api::Motor motor;
    ev3api::Motor motor;

public:
    void 走行する();

};
#endif  // CONTROL_DRIVING_CONTROL_H
