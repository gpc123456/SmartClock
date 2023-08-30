#ifndef STK8BA58_H
#define STK8BA58_H

#include <Arduino.h>
#include <Wire.h>

//--------POWER_MODE--------//
#define POWER_REG_ADDR 0x11
#define POWER_LOWPOWER_10MS 0x54
#define POWER_LOWPOWER_25MS 0x56
#define POWER_NORMAL 0x00 //仅在设置为LOWPOWER或SUSPEND后恢复NORMAL模式时使用

//--------OPEN_WDT--------//
#define WDT_REG_ADDR 0x34
#define ENABLE_WDT_50MS 0x06

//--------READ_DATA--------//
/*
WARNING:Reading the acceleration data registers shall
always start with the LSB part due to the data protection function.
*/
#define XOUT_LSB 0x02
#define YOUT_LSB 0x04
#define ZOUT_LSB 0x06
#define XOUT_MSB 0x03
#define YOUT_MSB 0x05
#define ZOUT_MSB 0x07

//--------FUNCTION--------//
short Init_STK8BA58();
float STK8BA58_ReadAcceleration_X();
float STK8BA58_ReadAcceleration_Y();
float STK8BA58_ReadAcceleration_Z();

#endif