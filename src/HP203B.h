#ifndef HP203B_H
#define HP203B_H

#include <Arduino.h>
#include <Wire.h>

short HP203B_Init(int OSR);
float HP203B_ReadAirPressure(int OSR);

#endif