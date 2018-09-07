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

/**
 * コンストラクタ
 * @param pValue 係数P
 * @param iValue 係数I
 * @param dValue 係数D
 */
PID::PID(float pValue,float iValue ,float dValue) {
    setPID(pValue, iValue, dValue);
}

/**
 * 係数設定
 * @param pValue 係数P
 * @param iValue 係数I
 * @param dValue 係数D
 */
void PID::setPID(float pValue,float iValue ,float dValue) {
    kp = pValue; /*比例定数*/
    ki = iValue; /*積分定数*/
    kd = dValue; /*微分定数*/
    diff[1] = 0;
    integral = 0.0;
}

/**
 * PID制御計算
 * @param nowValue 目標からの差
 */
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
