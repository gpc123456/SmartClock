#include "SmartClock.h"

void Pomodoro_StartPage()
{
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    EPD_2IN9_Display(Image_Pomodoro_StartPage);
    EPD_2IN9_Sleep();
}

void Pomodoro_ExitConfirm()
{
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    EPD_2IN9_Display(Image_Pomodoro_ExitConfirm);
    EPD_2IN9_Sleep();
}

void Pomodoro_HomePage_FullRefresh(UBYTE *Canvas, TimeAndDate TimeData, short battery_level, short PomodoroStatus, short time_remaining, float temper, short humidity, short tomato_number)
{
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    Paint_NewImage(Canvas, EPD_2IN9_WIDTH, EPD_2IN9_HEIGHT, 90, WHITE);
    Paint_SelectImage(Canvas);
    Paint_Clear(WHITE);
    Paint_DrawBitMap(Image_Pomodoro_HomePage);

    // DrawNowTime
    char t_hour[5];
    char t_min[5];
    TransNumberToStandNumberChar(t_hour, TimeData.hour);
    TransNumberToStandNumberChar(t_min, TimeData.minute);
    Paint_DrawString_EN(129, 3, t_hour, &Font12, BLACK, WHITE);
    Paint_DrawString_EN(144, 3, ":", &Font12, BLACK, WHITE);
    Paint_DrawString_EN(152, 3, t_min, &Font12, BLACK, WHITE);

    // DrawBatteryLevel
    switch (battery_level)
    {
    case 4:
        Paint_DrawImage(REVERSE_BatteryIcon_4, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 3:
        Paint_DrawImage(REVERSE_BatteryIcon_3, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 2:
        Paint_DrawImage(REVERSE_BatteryIcon_2, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 1:
        Paint_DrawImage(REVERSE_BatteryIcon_1, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 0:
        Paint_DrawImage(REVERSE_BatteryIcon_0, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    }

    // DrawSlogan
    if (PomodoroStatus == STATUS_WORKING && time_remaining >= 20)
    {
        Paint_DrawString_CN(60, 21, "良好的开始是成功的一半", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_WORKING && time_remaining > 5)
    {
        Paint_DrawString_CN(52, 21, "从来没有一种坚持会被辜负", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_WORKING)
    {
        Paint_DrawString_CN(108, 21, "快要成功啦~", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_REST_LESS5)
    {
        Paint_DrawString_CN(108, 21, "休息一下吧~", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_REST_5)
    {
        Paint_DrawString_CN(10, 21, "连续完成", &Font16CN, BLACK, WHITE);
        Paint_DrawString_EN(75, 21, "5", &Font20, BLACK, WHITE);
        Paint_DrawString_CN(90, 21, "个番茄时钟了，休息一下吧~", &Font16CN, BLACK, WHITE);
    }

    // DrawTimeRemaining
    char c_timeremaining[5];
    TransNumberToStandNumberChar(c_timeremaining, time_remaining);
    // DrawMin1
    switch (c_timeremaining[0])
    {
    case '0':
        Paint_DrawImage(Pomodoro_Num_0, 35, (114 - 1), 56, 35); // Y轴坐标为41
        break;
    case '1':
        Paint_DrawImage(Pomodoro_Num_1, 35, (114 - 1), 56, 35); // Y轴坐标为41
        break;
    case '2':
        Paint_DrawImage(Pomodoro_Num_2, 35, (114 - 1), 56, 35); // Y轴坐标为41
        break;
    }
    // DrawMin2
    switch (c_timeremaining[1])
    {
    case '0':
        Paint_DrawImage(Pomodoro_Num_0, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '1':
        Paint_DrawImage(Pomodoro_Num_1, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '2':
        Paint_DrawImage(Pomodoro_Num_2, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '3':
        Paint_DrawImage(Pomodoro_Num_3, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '4':
        Paint_DrawImage(Pomodoro_Num_4, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '5':
        Paint_DrawImage(Pomodoro_Num_5, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '6':
        Paint_DrawImage(Pomodoro_Num_6, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '7':
        Paint_DrawImage(Pomodoro_Num_7, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '8':
        Paint_DrawImage(Pomodoro_Num_8, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '9':
        Paint_DrawImage(Pomodoro_Num_9, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    }

    // DrawTimeRemainingBar
    if ((PomodoroStatus == STATUS_WORKING || PomodoroStatus == STATUS_REST_5) && time_remaining < 25)
    {
        Paint_DrawLine(89, 104, 85 + 5 * (25 - time_remaining), 104, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    }
    else if (time_remaining < 5)
    {
        Paint_DrawLine(89, 104, 85 + 25 * (5 - time_remaining), 104, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    }

    // DrawTemper
    char c_temp[10];
    String s_temp = String(temper, 1);
    strcpy(c_temp, s_temp.c_str());
    short temp_str_len = strlen(c_temp);
    Paint_DrawString_EN(36, 115, c_temp, &Font12, BLACK, WHITE);
    Paint_DrawString_CN(36 + 7 * temp_str_len + 1, 115, "℃", &Font12CN, BLACK, WHITE);

    // DrawHumidity
    char c_humidity[5];
    itoa(humidity, c_humidity, 10);
    short humidity_str_len = strlen(c_humidity);
    Paint_DrawString_EN(146, 115, c_humidity, &Font12, BLACK, WHITE);
    Paint_DrawString_EN(146 + 7 * humidity_str_len + 1, 115, "%", &Font12, BLACK, WHITE);

    // DrawTomatoNumber
    char c_TomatoNumber[5];
    itoa(tomato_number, c_TomatoNumber, 10);
    Paint_DrawString_EN(237, 115, c_TomatoNumber, &Font12, BLACK, WHITE);

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}

void Pomodoro_HomePage_PartRefresh_ExceptTomatoNumber(UBYTE *Canvas, TimeAndDate TimeData, short battery_level, short PomodoroStatus, short time_remaining, float temper, short humidity)
{
    DEV_Module_Init();
    EPD_2IN9_Init(PART_REFRESH);

    Paint_SelectImage(Canvas);

    // DrawNowTime
    Paint_ClearWindows(128, 2, 168, 16, WHITE);
    char t_hour[5];
    char t_min[5];
    TransNumberToStandNumberChar(t_hour, TimeData.hour);
    TransNumberToStandNumberChar(t_min, TimeData.minute);
    Paint_DrawString_EN(129, 3, t_hour, &Font12, BLACK, WHITE);
    Paint_DrawString_EN(144, 3, ":", &Font12, BLACK, WHITE);
    Paint_DrawString_EN(152, 3, t_min, &Font12, BLACK, WHITE);

    // DrawBatteryLevel
    Paint_ClearWindows(278, 1, 296, 16, WHITE);
    switch (battery_level)
    {
    case 4:
        Paint_DrawImage(REVERSE_BatteryIcon_4, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 3:
        Paint_DrawImage(REVERSE_BatteryIcon_3, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 2:
        Paint_DrawImage(REVERSE_BatteryIcon_2, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 1:
        Paint_DrawImage(REVERSE_BatteryIcon_1, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    case 0:
        Paint_DrawImage(REVERSE_BatteryIcon_0, 117, (280 - 1), 16, 16); // Y轴坐标为1
        break;
    }

    // DrawSlogan
    Paint_ClearWindows(1, 20, 295, 38, WHITE);
    if (PomodoroStatus == STATUS_WORKING && time_remaining >= 20)
    {
        Paint_DrawString_CN(60, 21, "良好的开始是成功的一半", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_WORKING && time_remaining > 5)
    {
        Paint_DrawString_CN(52, 21, "从来没有一种坚持会被辜负", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_WORKING)
    {
        Paint_DrawString_CN(108, 21, "快要成功啦~", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_REST_LESS5)
    {
        Paint_DrawString_CN(108, 21, "休息一下吧~", &Font16CN, BLACK, WHITE);
    }
    else if (PomodoroStatus == STATUS_REST_5)
    {
        Paint_DrawString_CN(10, 21, "连续完成", &Font16CN, BLACK, WHITE);
        Paint_DrawString_EN(75, 21, "5", &Font20, BLACK, WHITE);
        Paint_DrawString_CN(90, 21, "个番茄时钟了，休息一下吧~", &Font16CN, BLACK, WHITE);
    }

    // DrawTimeRemaining
    Paint_ClearWindows(113, 40, 186, 98, WHITE);
    char c_timeremaining[5];
    TransNumberToStandNumberChar(c_timeremaining, time_remaining);
    // DrawMin1
    switch (c_timeremaining[0])
    {
    case '0':
        Paint_DrawImage(Pomodoro_Num_0, 35, (114 - 1), 56, 35); // Y轴坐标为41
        break;
    case '1':
        Paint_DrawImage(Pomodoro_Num_1, 35, (114 - 1), 56, 35); // Y轴坐标为41
        break;
    case '2':
        Paint_DrawImage(Pomodoro_Num_2, 35, (114 - 1), 56, 35); // Y轴坐标为41
        break;
    }
    // DrawMin2
    switch (c_timeremaining[1])
    {
    case '0':
        Paint_DrawImage(Pomodoro_Num_0, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '1':
        Paint_DrawImage(Pomodoro_Num_1, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '2':
        Paint_DrawImage(Pomodoro_Num_2, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '3':
        Paint_DrawImage(Pomodoro_Num_3, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '4':
        Paint_DrawImage(Pomodoro_Num_4, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '5':
        Paint_DrawImage(Pomodoro_Num_5, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '6':
        Paint_DrawImage(Pomodoro_Num_6, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '7':
        Paint_DrawImage(Pomodoro_Num_7, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '8':
        Paint_DrawImage(Pomodoro_Num_8, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    case '9':
        Paint_DrawImage(Pomodoro_Num_9, 35, (150 - 1), 56, 35); // Y轴坐标为41
        break;
    }

    // DrawTimeRemainingBar
    Paint_ClearWindows(87, 102, 210, 105, WHITE);
    if ((PomodoroStatus == STATUS_WORKING || PomodoroStatus == STATUS_REST_5) && time_remaining < 25)
    {
        Paint_DrawLine(89, 104, 85 + 5 * (25 - time_remaining), 104, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    }
    else if (time_remaining < 5)
    {
        Paint_DrawLine(89, 104, 85 + 25 * (5 - time_remaining), 104, BLACK, DOT_PIXEL_3X3, LINE_STYLE_SOLID);
    }

    // DrawTemper
    Paint_ClearWindows(35, 114, 105, 128, WHITE);
    char c_temp[10];
    String s_temp = String(temper, 1);
    strcpy(c_temp, s_temp.c_str());
    short temp_str_len = strlen(c_temp);
    Paint_DrawString_EN(36, 115, c_temp, &Font12, BLACK, WHITE);
    Paint_DrawString_CN(36 + 7 * temp_str_len + 1, 115, "℃", &Font12CN, BLACK, WHITE);

    // DrawHumidity
    Paint_ClearWindows(145, 114, 208, 128, WHITE);
    char c_humidity[5];
    itoa(humidity, c_humidity, 10);
    short humidity_str_len = strlen(c_humidity);
    Paint_DrawString_EN(146, 115, c_humidity, &Font12, BLACK, WHITE);
    Paint_DrawString_EN(146 + 7 * humidity_str_len + 1, 115, "%", &Font12, BLACK, WHITE);

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}

void Pomodoro_HomePage_PartRefresh_TomatoNumber(UBYTE *Canvas, short tomato_number)
{
    DEV_Module_Init();
    EPD_2IN9_Init(PART_REFRESH);

    Paint_SelectImage(Canvas);

    // DrawTomatoNumber
    Paint_ClearWindows(236, 114, 295, 128, WHITE);
    char c_TomatoNumber[5];
    itoa(tomato_number, c_TomatoNumber, 10);
    Paint_DrawString_EN(237, 115, c_TomatoNumber, &Font12, BLACK, WHITE);

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}