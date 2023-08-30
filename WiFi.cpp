#include "SmartClock.h"

short ConfigDoneFlag = 0;

void SaveConfigCallback()
{
    ConfigDoneFlag = 1;
}

bool ConnectWiFi()
{
    WiFiManager wm;
    String SSID;
    String Password;

    // wm.resetSettings();
    wm.setTitle("SmartClock");
    wm.setBreakAfterConfig(true);
    wm.setConfigPortalBlocking(false);
    wm.setSaveConfigCallback(SaveConfigCallback);
    if (!wm.getWiFiIsSaved())
    { //无已保存WiFi时(首次开机)
        ConfigDoneFlag = 0;
        ShowWiFiConfigInfo();
        wm.startConfigPortal("SmartClock");
        wm.startWebPortal();
        while (ConfigDoneFlag == 0)
        {
            wm.process();
            if (Shaking() == IS_SHAKING)
            {
                wm.stopConfigPortal();
                wm.stopWebPortal();
                return FstConnectWiFiErr;
            }
        }

        if (WiFi.status() == WL_CONNECTED)
        {
            ShowWiFiConfigSuccess();
            delay(2000);
            ESP.reset();
            return FstConnectWiFiDone;
        }
        else
        {
            ShowWiFiConnectedErr();
            delay(3000);
            return FstConnectWiFiErr;
        }
    }
    else
    {
        short UCWiFiTimes = 0;
        SSID = wm.getWiFiSSID();
        Password = wm.getWiFiPass();
        WiFi.begin(SSID, Password);
        while (WiFi.status() != WL_CONNECTED && UCWiFiTimes <= 40)
        {
            if (WiFi.status() == WL_WRONG_PASSWORD || WiFi.status() == WL_NO_SSID_AVAIL)
            {
                break;
            }
            UCWiFiTimes++;
            delay(1000);
        }
        if (WiFi.status() == WL_CONNECTED)
        {
            return FstConnectWiFiDone;
        }
        else
        {
            ConfigDoneFlag = 0;
            ShowWiFiConfigInfo();
            wm.startConfigPortal("SmartClock");
            wm.startWebPortal();
            while (ConfigDoneFlag == 0)
            {
                wm.process();
                if (Shaking() == IS_SHAKING)
                {
                    wm.stopConfigPortal();
                    wm.stopWebPortal();
                    return FstConnectWiFiErr;
                }
            }

            if (WiFi.status() == WL_CONNECTED)
            {
                ShowWiFiConfigSuccess();
                delay(2000);
                ESP.reset();
                return FstConnectWiFiDone;
            }
            else
            {
                ShowWiFiConnectedErr();
                delay(3000);
                return FstConnectWiFiErr;
            }
        }
    }
}
