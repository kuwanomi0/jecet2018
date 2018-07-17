/**
 ******************************************************************************
 ** ファイル名 : app.cpp
 **
 ** 概要 : 2輪倒立振子ライントレースロボットのTOPPERS/HRP2用C++サンプルプログラム
 **
 ** 注記 : sample_cpp (ライントレース/尻尾モータ/超音波センサ/リモートスタート)
 ******************************************************************************
 **/

#include "ev3api.h"
#include "app.h"

#include "runner/Driver.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/* Bluetooth */
// static int32_t   bt_cmd = 0;
// static FILE     *bt = NULL;

Driver* driver;

//*****************************************************************************
// 関数名 : main_task
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : メインタスク
//*****************************************************************************
void main_task(intptr_t unused)
{
    driver = new Driver();

    // bt = ev3_serial_open_file(EV3_SERIAL_BT);
    // assert(bt != NULL);

    act_tsk(BT_TASK);

    driver->exec();

    // ter_tsk(BT_TASK);
    // fclose(bt);

    ext_tsk();
}

//*****************************************************************************
// 関数名 : controller_task
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : コントローラータスク
//*****************************************************************************
void controller_task(intptr_t unused)
{
    driver->funk();
}

//*****************************************************************************
// 関数名 : cyc_handler
// 引数   : 拡張情報
// 返り値 : なし
// 概要   : 周期ハンドラ(4ms)
//*****************************************************************************
void cyc_handler(intptr_t unused)
{
    act_tsk(CONTROLLER_TASK);
}

//*****************************************************************************
// 関数名 : bt_task
// 引数 : unused
// 返り値 : なし
// 概要 : Bluetooth通信によるリモートスタート。 Tera Termなどのターミナルソフトから、
//       ASCIIコードで1を送信すると、リモートスタートする。
//*****************************************************************************
void bt_task(intptr_t unused)
{
    // while(1)
    // {
    //     uint8_t c = fgetc(bt);
    //     switch(c)
    //     {
    //     case '0':
    //         bt_cmd = 0;
    //         break;
    //     case '1':
    //         bt_cmd = 1;
    //         break;
    //     case '6':
    //         bt_cmd = 6;
    //         break;
    //     case '\r':
    //         bt_cmd = '\r';
    //         break;
    //     default:
    //         break;
    //     }
    //     fputc(c, bt); /* エコーバック */
    // }
}
