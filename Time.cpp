#include "SmartClock.h"

RTC_PCF8563 rtc_pcf8563;

bool InitRTC()
{
    Wire.begin(12, 14);
    if (rtc_pcf8563.begin())
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool UpdateTime() //请在连接WIFI后执行本函数，如网络未连接可跳过
{
    short SyncTimeTryTimes = 0;
    WiFiUDP ntpUDP;
    NTPClient timeClient(ntpUDP, "ntp1.nim.ac.cn");
    timeClient.begin();
    timeClient.forceUpdate();

    while (timeClient.isTimeSet() == 0 && SyncTimeTryTimes < 5)
    {
        timeClient.forceUpdate();
        SyncTimeTryTimes++;
        Serial.println("Try UpdateTime Again!");
    }

    Wire.begin(12, 14);

    if (rtc_pcf8563.begin() && timeClient.isTimeSet() == 1)
    {
        UnixTime stamp(8);
        stamp.getDateTime(timeClient.getEpochTime());
        rtc_pcf8563.adjust(DateTime(stamp.year, stamp.month, stamp.day, stamp.hour, stamp.minute, stamp.second));
        rtc_pcf8563.start();
        Serial.println("TimeSet Done!");
        timeClient.end();
        return TimeUpdateDone;
    }
    else
    {
        Serial.println("TimeSet Err!");
        timeClient.end();
        return TimeUpdateErr;
    }
}

TimeAndDate ReadTimeAndDate()
{
    Wire.begin(12, 14);
    TimeAndDate TimeData;
    DateTime now = rtc_pcf8563.now();
    TimeData.year = now.year();
    TimeData.month = now.month();
    TimeData.day = now.day();
    TimeData.hour = now.hour();
    TimeData.minute = now.minute();
    TimeData.second = now.second();
    if (now.dayOfTheWeek() == 0)
    {
        TimeData.weekday = 7;
    }
    else
    {
        TimeData.weekday = now.dayOfTheWeek();
    }
    return TimeData;
}