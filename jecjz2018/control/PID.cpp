/**
 ******************************************************************************
 ** ファイル名 : PID.cpp
 ** クラス名   : PID
 **
 ** 概要 : PID制御を行うための処理をするクラス
 ******************************************************************************
 **/
#include "PID.h"

#define LIMIT   100.0 /* 最大最小の制限 */

/* PID制御計算メソッド */
int PID::calcControl(int nowValue) {
    float pControl, iControl, dControl, total;

    diff[0]   = diff[1];
    diff[1]   = nowValue;
    if(diff[0] == diff[1]){
        integral = 0.0F;
    }
    else {
        integral += (diff[1] + diff[0]) / 2.0;
    }

    pControl = kp * diff[1];
    iControl = ki * integral;
    dControl = kd * (diff[1] - diff[0]);

    total = pControl + iControl + dControl;

    /* 飽和処理 */
    if (total > LIMIT) {
        total = LIMIT;
    }
    else if (total < -LIMIT) {
        total = -LIMIT;
    }

    return static_cast<int>(total);
}
