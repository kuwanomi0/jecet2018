/**
 ******************************************************************************
 ** ファイル名 : Driver.cpp
 ** クラス名   : Driver
 **
 ** 概要 : 走行体に指示するクラス
 ******************************************************************************
 **/
#include "Driver.h"

#include "ev3api.h"

Driver::Driver() {
    runner = new Runner();
}

void Driver::exec() {
    /* LCD画面表示 */
    char buf[64];
    runner->start();
    ER er = ev3_sta_cyc(CYC_HANDLER);   //周期ハンドラを起動
    sprintf(buf, "main_task: error_code=%d", MERCD(er) );   // APIのエラーコードの表示
    //ev3_lcd_draw_string(buf, 0, CALIB_FONT_HEIGHT*1);     // の仕方です。
}

void Driver::funk() {
    syslog(LOG_NOTICE, "test %3d\r", testc++);
}
