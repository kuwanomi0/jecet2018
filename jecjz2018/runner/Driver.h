/**
 ******************************************************************************
 ** ファイル名 : Driver.h
 ** クラス名   : Driver
 **
 ** 概要 : 走行体に指示するクラス
 ******************************************************************************
 **/
#ifndef RUNNER_DRIVER_H
#define RUNNER_DRIVER_H

#include "Runner.h"
#include "../scenario/Course.h"
#include "Clock.h"

class Driver
{
private:
    Runner* runner;
    Course* mCourse;
    Course dCourse[3] = {
    /*  {  距離,時間,衝撃,障害,  前進,旋回,尻尾,Gyro  P   ,    I   ,    D  ,目標RGB,走行法} */
        {     1,    0,  0,  0,     150,  0, 95,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },  //  1 初期化配列
        {     0,  150,  0,  0,     115,  0, 96,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },  //  2 S
        { 99990,    0,  0,  0,      70,  0,  5,   0, 0.1000F, 0.0000F, 1.0000F, 1.00F, 1 }  //  4 直線
    };
    Course lCourse[25] =  {
        {     1,    0,  0,  0,     150,  0, 95,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  1 初期化配列
        {     0,  150,  0,  0,     115,  0, 96,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  2 S
        {  2500,    0,  0,  0,     155,  0,  5,   0, 0.0500F, 0.0000F, 1.1000F, 1.00F, 1 },  //  3 直線
        {  1500,    0,  0,  0,     115,  0,  5,   0, 0.0700F, 0.0001F, 1.0000F, 1.00F, 1 },  //  4 左カーブ
        {  1500,    0,  0,  0,     150,  0,  5,   0, 0.0500F, 0.0000F, 1.1000F, 1.00F, 1 },  //  5 直線
        {   700,    0,  0,  0,     105,  0,  5,   0, 0.0920F, 0.0001F, 1.5000F, 0.85F, 1 },  //  6 右カーブ
        {   550,    0,  0,  0,     130,  0,  5,   0, 0.0500F, 0.0000F, 1.2000F, 0.85F, 1 },  //  7 直線
        {   800,    0,  0,  0,     100,  0,  5,   0, 0.0920F, 0.0001F, 1.5000F, 0.85F, 1 },  //  8 右カーブ
        {  2100,    0,  0,  0,     155,  0,  5,   0, 0.0500F, 0.0001F, 1.1000F, 1.00F, 1 },  //  9 直進
        {   200,    0,  0,  0,      30,  0,  5,   0, 0.0900F, 0.0001F, 0.7000F, 1.15F, 1 },  // 10 減速1
        /* ここでゴール */
        {  1100,    0,  0,  0,      30,  0,  5,   0, 0.0900F, 0.0001F, 0.7000F, 1.50F, 1 },  // 11 左カーブ及び灰色
        {     0,    0,  0, 10,      10,  0, 70,   0, 0.0500F, 0.0001F, 0.7000F, 1.10F, 1 },  // 12 ルックアップ検知まで
        /* ここからルックアップ */
        {     0,  100,  0,  0,      30,  0, 63,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 13 尻尾走行切り替え
        {     0,  700,  0,  0,       0,  0, 63,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 14 安定化停止
        {   320,    0,  0,  0,      10,  0, 63,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 15 シングル通過
        {     0, 1500,  0,  0,       0,  0, 63,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 16 安定化停止
        {   370,    0,  0,  0,     -10,  0, 63,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 17 バック通過
        {     0, 1200,  0,  0,       0,  0, 63,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 18 安定化停止
        {   410,    0,  0,  0,      10,  0, 63,   0, 0.0700F, 0.0002F, 0.4000F, 0.98F, 0 },  // 19 ダブル通過(PID ON)
        {    30,    0,  0,  0,       3,  0, 63,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 19 ダブル通過(PID ON)
        /* ここからガレージ */
        {    10,    0,  0,  0,     -65,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 20 走行体角度上げ
        {   280,    0,  0,  0,      10,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 21 灰色通過
        {   203,    0,  0,  0,      10,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 22 ガレージ
        {     0,    0,  0,  0,       0,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 23 完全停止
        {     0,    0,  0,  0,       0,  0, 81,   0, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 }   // 24 完全停止用終端配列
    };
    Course rCourse[21] =  {
        {     1,    0,  0,  0,     100,  0, 95,   0, 0.0300F, 0.0000F, 1.0000F, 1.00F, 1 },  //  1 初期化配列
        {     0,  150,  0,  0,     100,  0, 96,   0, 0.0700F, 0.0000F, 1.0000F, 1.00F, 1 },  //  2
        {  1900,    0,  0,  0,     155,  0,  5,   0, 0.0500F, 0.0000F, 1.1000F, 1.00F, 1 },  //  3 直進
        {  1850,    0,  0,  0,     130,  0,  5,   0, 0.0920F, 0.0001F, 1.2000F, 1.15F, 1 },  //  4 左カーブ
        {   400,    0,  0,  0,     130,  0,  5,   0, 0.0500F, 0.0001F, 1.3000F, 1.15F, 1 },  //  5 直進
        {   700,    0,  0,  0,     105,  0,  5,   0, 0.0970F, 0.0001F, 1.5000F, 1.15F, 1 },  //  6 左カーブ
        {   700,    0,  0,  0,     110,  0,  5,   0, 0.0970F, 0.0001F, 1.5000F, 0.85F, 1 },  //  7 右カーブ
        {   550,    0,  0,  0,     130,  0,  5,   0, 0.0500F, 0.0000F, 1.1000F, 1.00F, 1 },  //  8 直進
        {  1260,    0,  0,  0,     105,  0,  5,   0, 0.0920F, 0.0001F, 1.5000F, 0.85F, 1 },  //  9 右カーブ
        {  2300,    0,  0,  0,     150,  0,  5,   0, 0.0500F, 0.0000F, 1.1000F, 1.00F, 1 },  // 10 直進
        /* ここでゴール */
        {  1100,    0,  0,  0,      30,  0,  5,   0, 0.0900F, 0.0001F, 0.8000F, 1.50F, 1 },  // 11 左カーブ及び灰色
        { 20000,    0,130,  0,      20,  0,  5,   0, 0.0900F, 0.0001F, 0.8000F, 1.00F, 1 },  // 12 シーソ衝突まで
        /* ここからシーソー */
        {   100,    0,  0,  0,      -7,  0,  5,  -5, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },  // 13 バック
        {  2000,    0,130,  0,     120,  0,  5,   2, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },  // 14 シーソ突入
        {   380, 5000,  0,  0,     120,  0,  5,  -7, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },  // 15 シーソ突入後のぼり
        {   200, 2000,  0,  0,     -60,  0,  5, -10, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },  // 16 シーソ切り替わり
        {   180,    0,  0,  0,      30,  0,  5,   5, 0.0000F, 0.0000F, 0.0000F, 1.00F, 1 },  // 17 シーソ降下
        /* ここから着地後動作 */
        {     0,  200,  0,  0,      80,  0, 80, -20, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 18 尻尾倒立処理
        {    20,    0,  0,  0,      10,  0, 80, -20, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 19 少し前進
        {     0,    0,  0,  0,       0,  0, 80, -10, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 },  // 20 完全停止用
        {     0,    0,  0,  0,       0,  0, 80, -10, 0.0000F, 0.0000F, 0.0000F, 1.00F, 0 }   // 21 完全停止用終端配列
    };
    Clock* clock;
    int beforeDistance;
    int beforeClock;
    int courseNumber = 0;
public:
    Driver();
    void start();
    void exec();
    int courseChange();
    void btUpdate();

};
#endif  // RUNNER_DRIVER_H
