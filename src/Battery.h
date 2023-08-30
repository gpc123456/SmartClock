#ifndef BATTERY_H
#define BATTERY_H
#include <Arduino.h>

short ReadBatteryLevel();//返回值4-0,4到1电量逐渐降低。0为极低电量,此时应及时充电

#endif