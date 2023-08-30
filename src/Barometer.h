#ifndef PRESSENSOR_H
#define PRESSENSOR_H

#include "HP203B.h"
#define INIT_BAROMETER_OK 0

short InitBarometer();
float ReadAirPressure();

#endif