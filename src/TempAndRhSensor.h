#ifndef TEMPANDRHSENSOR_H
#define TEMPANDRHSENSOR_H

#include "AHT20.h"

#define INIT_TEMPRHSENSOR_OK 0

short InitTempAndRhSensor();
TempAndRhData ReadTempAndRh();

#endif