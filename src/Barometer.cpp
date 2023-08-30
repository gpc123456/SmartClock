#include "Barometer.h"

short InitBarometer()
{
    return (HP203B_Init(128));
}

float ReadAirPressure()
{
    // OSR可选128、256、512、1024、2048、4096.数值越大精度越高
    return (HP203B_ReadAirPressure(1024));
}
