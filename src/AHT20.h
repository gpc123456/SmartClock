#ifndef AHT20_H
#define AHT20_H

#include <Arduino.h>
#include <Wire.h>

struct TempAndRhData
{
    float Temperature;
    float Humidity;
};

TempAndRhData AHT20_GetTempAndRh();
short AHT20_Init();

#endif