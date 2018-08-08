/**
 ******************************************************************************
 ** ファイル名 : Course.h
 ** クラス名   : Course
 **
 ** 概要 : コース情報を格納するクラス
 ******************************************************************************
 **/
#ifndef COURSE_H
#define COURSE_H

class Course {

private:
    int dis;        /* 設定距離 */
    int forward;    /* 前進速度 */
    int turn;       /* 旋回速度 */
    int tailAngle;  /* 尻尾角度 */
    float kp;       /* 係数P */
    float ki;       /* 係数I */
    float kd;       /* 係数D */
    int style;  /* 走行方法  0:尻尾走行 1:倒立走行 */

public:
    /**
     * 関数名 : Course
     * 引数   : int dis, int forward, int turn, int tailAngle, float kp, float ki, float kd, int style
     * 概要   : コンストラクタ
     */
    Course(int dis, int forward, int turn, int tailAngle, float kp, float ki, float kd, int style) {
        this->dis = dis;
        this->forward = forward;
        this->turn = turn;
        this->tailAngle = tailAngle;
        this->kp = kp;
        this->ki = ki;
        this->kd = kd;
        this->style = style;
    }
    int getDis() {
        return dis;
    }
    int getForward() {
        return forward;
    }
    int getTurn() {
        return turn;
    }
    int getTailAngle() {
        return tailAngle;
    }
    float getP() {
        return kp;
    }
    float getI() {
        return ki;
    }
    float getD() {
        return kd;
    }
    int getStyle() {
        return style;
    }
    void setForward(int forward) {
        this->forward = forward;
    }
};

#endif
