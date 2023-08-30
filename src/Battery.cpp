#include "Battery.h"

short ReadBatteryLevel()
{
    short BatteryVoltage;
    pinMode(A0, INPUT);
    BatteryVoltage = analogRead(A0);
    if (BatteryVoltage >= 738)
    {
        return 4;
    }
    else if (BatteryVoltage >= 710)
    {
        return 3;
    }
    else if (BatteryVoltage >= 666)
    {
        return 2;
    }
    else if (BatteryVoltage >= 625)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}