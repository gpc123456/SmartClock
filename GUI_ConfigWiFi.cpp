#include "SmartClock.h"

void ShowWiFiConfigInfo()
{
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    EPD_2IN9_Display(Image_ConfigWiFi);
    EPD_2IN9_Sleep();
}

void ShowWiFiConfigSuccess()
{
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    EPD_2IN9_Display(Image_WiFiConfigSuccess);
    EPD_2IN9_Sleep();
}

void ShowWiFiConnectedErr()
{
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    EPD_2IN9_Display(Image_WiFiConnectedErr);
    EPD_2IN9_Sleep();
}