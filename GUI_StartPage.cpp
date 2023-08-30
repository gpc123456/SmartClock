#include "SmartClock.h"

void StartPage()
{
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    EPD_2IN9_Clear();
    delay(500);
    EPD_2IN9_Display(Image_StartPage);
    EPD_2IN9_Sleep();

    if (InitAllSensor() != AllSensorInitDone)
    {
        delay(50);
        DEV_Module_Init();
        EPD_2IN9_Init(FULL_REFRESH);
        EPD_2IN9_Display(Image_InitSensorErr);
        EPD_2IN9_Sleep();
        system_deep_sleep_instant(0);
    }
}