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
    int time;       /* 設定時間 */
    int impact;     /* 衝撃検知量 */
    int sonarDis;   /* 障害物検知距離 */
    int forward;    /* 前進速度 */
    int turn;       /* 旋回速度 */
    int tailAngle;  /* 尻尾角度 */
    int gyroOffset; /* ジャイロオフセット */
    float kp;       /* 係数P */
    float ki;       /* 係数I */
    float kd;       /* 係数D */
    float krgb;     /* RGB目標値係数 */
    int style;      /* 走行方法  0:尻尾走行 1:倒立走行 */

public:
    /**
     * コンストラクタ
     * @param dis
     * @param time
     * @param impact
     * @param sonarDis
     * @param forward
     * @param turn
     * @param tailAngle
     * @param gyroOffset
     * @param kp
     * @param ki
     * @param kd
     * @param krgb
     * @param style
     */
    Course(int dis, int time, int impact, int sonarDis, int forward, int turn, int tailAngle, int gyroOffset, float kp, float ki, float kd, float krgb, int style) {
        this->dis = dis;
        this->time = time;
        this->impact = impact;
        this->sonarDis = sonarDis;
        this->forward = forward;
        this->turn = turn;
        this->tailAngle = tailAngle;
        this->gyroOffset = gyroOffset;
        this->kp = kp;
        this->ki = ki;
        this->kd = kd;
        this->krgb = krgb;
        this->style = style;
    }
    int getDis() {
        return dis;
    }
    int getTime() {
        return time;
    }
    int getImpact() {
        return impact;
    }
    int getSonarDis() {
        return sonarDis;
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
    int getGyroOffset() {
        return gyroOffset;
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
    float getKrgb() {
        return krgb;
    }
    int getStyle() {
        return style;
    }
};

#endif
