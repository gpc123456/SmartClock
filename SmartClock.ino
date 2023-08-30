#include "SmartClock.h"

UBYTE *Canvas;
bool HomePageFirstDisplayTag;
WeatherData weatherdata;
TempAndRhData tempandrh;
float Nowtemperature;
short Nowhumidity;
short Nowairpressure;
bool FullRefreshTag;
unsigned int RefreshDatatimer;
short NowScreen;

void setup()
{
    weatherdata.DataAvailableTag = WDATA_UNAVAILABLE;
    Serial.begin(115200);
    StartPage();
    if (ConnectWiFi() == FstConnectWiFiDone)
    {
        UpdateTime();
        UpdateWeather(&weatherdata);
    }
    UWORD Imagesize = ((EPD_2IN9_WIDTH % 8 == 0) ? (EPD_2IN9_WIDTH / 8) : (EPD_2IN9_WIDTH / 8 + 1)) * EPD_2IN9_HEIGHT;
    if ((Canvas = (UBYTE *)malloc(Imagesize)) == NULL)
    {
        while (true)
        {
        }
    }
    tempandrh = ReadTempAndRh();
    Nowtemperature = SimplifyTemperatureToOneDecimal(tempandrh.Temperature);
    Nowhumidity = round(tempandrh.Humidity);
    Nowairpressure = round(ReadAirPressure());
    RefreshDatatimer = 1;
    FullRefreshTag = NEED_FULLREFRESH;
    HomePageFirstDisplayTag == 0;
    NowScreen = HOMEPAGE;
}

TimeAndDate NowTime;
short OldHour;
short OldMinute;

void loop()
{
    wifi_station_disconnect();
    wifi_set_opmode(NULL_MODE);
    wifi_fpm_set_sleep_type(LIGHT_SLEEP_T);
    wifi_fpm_open();
    wifi_fpm_do_sleep(500000); // Sleep range = 10000 ~ 268,435,454 uS (0xFFFFFFE, 2^28-1)
    delay(500 + 1);            // delay needs to be 1 mS longer than sleep or it only goes into Modem Sleep

    RefreshDatatimer++;
    Wire.begin(12, 14);

    if (NowScreen == HOMEPAGE)
    {
        NowTime = ReadTimeAndDate();
        if (HomePageFirstDisplayTag == 0)
        {
            WiFi.forceSleepBegin(0xFFFFFFF);
            delay(10);
            HomePage_FullRefresh(Canvas, NowTime, weatherdata, Nowtemperature, Nowhumidity, Nowairpressure, ReadBatteryLevel());
            OldHour = NowTime.hour;
            OldMinute = NowTime.minute;
            HomePageFirstDisplayTag = 1;
        }

        if ((NowTime.hour == 12 && NowTime.minute == 0 && FullRefreshTag == NEED_FULLREFRESH) || (NowTime.hour == 0 && NowTime.minute == 0 && FullRefreshTag == NEED_FULLREFRESH))
        {
            WiFi.forceSleepBegin(0xFFFFFFF);
            delay(10);
            HomePage_FullRefresh(Canvas, NowTime, weatherdata, Nowtemperature, Nowhumidity, Nowairpressure, ReadBatteryLevel());
            OldHour = NowTime.hour;
            OldMinute = NowTime.minute;
            FullRefreshTag = NONEED_FULLREFRESH;
        }
        if (NowTime.minute != OldMinute)
        {
            WiFi.forceSleepBegin(0xFFFFFFF);
            delay(10);
            HomePage_PartRefreshTime_Temperature_Humidity_Airpressure_Battery(Canvas, NowTime, Nowtemperature, Nowhumidity, Nowairpressure, ReadBatteryLevel());
            OldMinute = NowTime.minute;
        }
        if (NowTime.hour != OldHour)
        {
            WiFi.forceSleepBegin(0xFFFFFFF);
            delay(10);
            HomePage_PartRefreshWeather(Canvas, weatherdata, NowTime);
            OldHour = NowTime.hour;
            FullRefreshTag = NEED_FULLREFRESH; //全刷1小时后再重置全刷标志位，防止重复刷新
        }

        if (RefreshDatatimer % 3 == 0)
        {
            // WiFi.forceSleepBegin(0xFFFFFFF);
            // delay(10);
            if (Direction() == FRONT_DOWN)
            {
                NowScreen = POMODORO;
                PomodoroFirstStartFlag = POMODORO_FIRST_START;
            }
        }
    }
    else if (NowScreen == POMODORO)
    {
        App_Pomodoro(Canvas, ReadBatteryLevel(), Nowtemperature, Nowhumidity);
    }

    if (RefreshDatatimer % 50 == 0)
    {
        WiFi.forceSleepBegin(0xFFFFFFF);
        delay(10);
        tempandrh = ReadTempAndRh();
        Nowtemperature = SimplifyTemperatureToOneDecimal(tempandrh.Temperature);
        Nowhumidity = round(tempandrh.Humidity);
        Nowairpressure = round(ReadAirPressure());
    }

    if (RefreshDatatimer % 7200 == 0)
    {
        WiFi.forceSleepWake();
        wifi_fpm_close();              //	disable	force	sleep	function
        wifi_set_opmode(STATION_MODE); //	set	station	mode
        wifi_station_connect();        //	connect	to	AP
        delay(5000);
        Serial.println(UpdateTime());
        if (UpdateWeather(&weatherdata) == UPDATE_WEATHER_SUCCESS)
        {
            Serial.println("Weather Update!");
            RefreshDatatimer == 1;
        }
    }
    if (RefreshDatatimer == 4294967293)
    {
        RefreshDatatimer = 1; //防止数据溢出
    }
}