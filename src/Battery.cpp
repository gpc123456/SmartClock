#include "Battery.h"

// 当前电量计算模式使用100K与10K电阻进行分压
// 电池电压为: U(ADC)/0.0909

short ReadBatteryLevel()
{
    pinMode(A0, INPUT);
    float BatteryPinAnalogRead = analogRead(A0);
    short BatteryVoltage= ((1000.0/1024.0)*BatteryPinAnalogRead)/0.0909;
    Serial.println(BatteryVoltage);
    if (BatteryVoltage >= 3900)
    {
        return 4;
    }
    else if (BatteryVoltage >= 3800)
    {
        return 3;
    }
    else if (BatteryVoltage >= 3700)
    {
        return 2;
    }
    else if (BatteryVoltage >= 3400)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}