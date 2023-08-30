#include "SmartClock.h"

bool InitAllSensor()
{
    short R_InitAccelerometer;
    short R_InitBarometer;
    short R_InitTempAndRhSensor;
    short R_InitRTC;

    R_InitAccelerometer = InitAccelerometer();
    R_InitBarometer = InitBarometer();
    R_InitTempAndRhSensor = InitTempAndRhSensor();
    R_InitRTC = InitRTC();

    if ((R_InitAccelerometer | R_InitBarometer | R_InitTempAndRhSensor | R_InitRTC) == 0)
    {
        return AllSensorInitDone;
    }
    else
    {
        return SensorInitErr;
    }
}
