#include "TempAndRhSensor.h"

short InitTempAndRhSensor()
{
    return (AHT20_Init());
}

TempAndRhData ReadTempAndRh()
{
    return (AHT20_GetTempAndRh());
}