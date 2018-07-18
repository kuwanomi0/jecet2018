/**
 ******************************************************************************
 ** ファイル名 : PID.h
 ** クラス名   : PID
 **
 ** 概要 : PID制御の計算を行うクラス
 ******************************************************************************
 **/
#ifndef CONTROL_PID_H
#define CONTROL_PID_H

class PID
{
private:
    float kp; /*比例定数*/
    float ki; /*積分定数*/
    float kd; /*微分定数*/
    int diff[2]; /* カラー格納用変数 */
    float integral; /* 積分計算用変数 */

public:
    PID(float pValue,float iValue ,float dValue) {
        setPID(pValue, iValue, dValue);
    }
    int calcControl(int nowValue);
    void setPID(float pValue,float iValue ,float dValue) {
        kp = pValue; /*比例定数*/
        ki = iValue; /*積分定数*/
        kd = dValue; /*微分定数*/
        diff[1] = 0;
        integral = 0.0;
    }

};
#endif  // CONTROL_PID_H
