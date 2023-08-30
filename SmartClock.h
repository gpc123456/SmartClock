#ifndef SMARTCLOCKFUNCTION_H
#define SMARTCLOCKFUNCTION_H

//-------------INCLUDE-------------//
/*Arduino*/
#include <Arduino.h>
/*Sensor*/
#include "src/Accelerometer.h"
#include "src/Barometer.h"
#include "src/TempAndRhSensor.h"
/*WiFi*/
#include <ESP8266WiFi.h>
#include "src/WiFiManager.h"
/*Time*/
#include <WiFiUdp.h>
#include "src/RTClib.h"
#include "src/NTPClient.h"
#include "src/UnixTime.h"
/*Weather*/
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
/*E-paper Display*/
#include "src/DEV_Config.h"
#include "src/EPD_2in9.h"
#include "src/GUI_Paint.h"
#include "src/ImageData.h"
#include "src/TimeNumber.h"
#include "src/WeatherIcon.h"
#include "src/BatteryIcon.h"
/*Battery*/
#include "src/Battery.h"
/*Storage*/
#include <LittleFS.h>
/*Vibration*/
#include "src/Vibration.h"

//-------------DEFINE-------------//
/*I2C*/
#define I2C_SDA 12
#define I2C_SCL 14

/*Sensor*/
#define AllSensorInitDone 0
#define SensorInitErr 1

/*Epaper*/
#define FULL_REFRESH 0
#define PART_REFRESH 1
#define NEED_FULLREFRESH 0
#define NONEED_FULLREFRESH 1

/*Time*/
#define RTCInitDone 1
#define RTCInitErr 0
#define TimeUpdateDone 0
#define TimeUpdateErr 1

/*WiFi*/
#define FstConnectWiFiDone 0
#define FstConnectWiFiErr 1

/*Weather*/
#define UPDATE_WEATHER_SUCCESS 1
#define UPDATE_WEATHER_ERR 0
#define WDATA_AVAILABLE 1
#define WDATA_UNAVAILABLE 0

/*Pomodoro*/
#define POMODORO_FIRST_START 0
#define POMODORO_NOFIRST_START 1
#define STATUS_WORKING 0
#define STATUS_REST_LESS5 1
#define STATUS_REST_5 2
#define POMODORO_RUN 0
#define POMODORO_EXIT 1

/*AppList*/
#define HOMEPAGE 0
#define POMODORO 1

//-------------DataStructure-------------//
struct TimeAndDate
{
    short year;
    short month;
    short day;
    short hour;
    short minute;
    short second;
    short weekday;
};

struct WeatherData
{
    //首次初始化后请先将DataAvailableTag设为WDATA_UNAVAILABLE,待首次数据更新成功后改为WDATA_AVAILABLE,避免读空数据
    bool DataAvailableTag;
    TimeAndDate UpdateTime;
    char Location[100];
    char Date[3][15];
    char code_day[3][5];
    char code_night[3][5];
    char temp_high[3][5];
    char temp_low[3][5];
    char pRainfall[3][7];
};

//-------------GlobalVariableDeclaration-------------//
/*HomePage*/
extern short NowScreen;
extern bool HomePageFirstDisplayTag;
/*Pomodoro*/
extern bool PomodoroFirstStartFlag;
extern uint32_t EndTime_Unix;
extern short OldRemainTime;
extern short NowPomodoroStatus;
extern short ContinuedTomatoTime;

//-------------Function-------------//
/*GUI*/
//StartPage
void StartPage();
//HomePage
void HomePage_FullRefresh(UBYTE *Canvas, TimeAndDate TimeData, WeatherData weatherdata, float Temper, short Humidity, short Pressure, short BatteryLevel);
void HomePage_PartRefreshTime_Temperature_Humidity_Airpressure_Battery(UBYTE *Canvas, TimeAndDate TimeData, float temperature, short humidity, short airpressure, short batterylevel);
void HomePage_PartRefreshWeather(UBYTE *Canvas, WeatherData weatherdata, TimeAndDate TimeData);
//Pomodoro
void Pomodoro_StartPage();
void Pomodoro_ExitConfirm();
void Pomodoro_HomePage_FullRefresh(UBYTE *Canvas, TimeAndDate TimeData, short battery_level, short PomodoroStatus, short time_remaining, float temper, short humidity, short tomato_number);
void Pomodoro_HomePage_PartRefresh_ExceptTomatoNumber(UBYTE *Canvas, TimeAndDate TimeData, short battery_level, short PomodoroStatus, short time_remaining, float temper, short humidity);
void Pomodoro_HomePage_PartRefresh_TomatoNumber(UBYTE *Canvas, short tomato_number);

/*Sensor*/
bool InitAllSensor();

/*Time*/
bool InitRTC();
bool UpdateTime();
TimeAndDate ReadTimeAndDate();

/*WiFi*/
bool ConnectWiFi();
void ShowWiFiConfigInfo();//GUI
void ShowWiFiConfigSuccess();//GUI
void ShowWiFiConnectedErr();//GUI

/*Weather*/
bool UpdateWeather(WeatherData *weatherdata);
short FindWeatherData(WeatherData weatherdata, TimeAndDate timedata);

/*DataProcessing*/
void TransNumberToStandNumberChar(char CharType[5], short NumType);//将绝对值<100的整数(5)转化为2位数字的格式(05)并输出到字符数组中
float SimplifyTemperatureToOneDecimal(float rawdata); //将温度传感器返回的两位小数转化为一位小数，以0.5为单位进行舍入

/*Storage*/
short GetTomatoNumber(TimeAndDate TimeData);//App_Pomodoro
void AddTomatoNumber(TimeAndDate TimeData, short WillAddTomatoNumber);//App_Pomodoro

/*APP*/
void App_Pomodoro(UBYTE *Canvas, short BatteryLevel, float NowTemp, short NowHumidity);

#endif