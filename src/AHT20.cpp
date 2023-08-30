#include "AHT20.h"

short AHT20_Init()
{
    byte StateCode;
    short InitResult;
    Wire.begin(12, 14);
    delay(40);
    Wire.beginTransmission(0x38);
    Wire.write(0x71);
    InitResult = Wire.endTransmission();
    if (InitResult == 0)
    {
        Wire.requestFrom(0x38, 1);
        StateCode = Wire.read();
        if (bitRead(StateCode, 3) == 0)
        {
            // Serial.println("Calibration Mode!");
            Wire.beginTransmission(0x38);
            Wire.write(0xBE);
            Wire.write(0x08);
            Wire.write(0x00);
            return (Wire.endTransmission());
        }
        else
        {
            return InitResult;
        }
    }
    else
    {
        return InitResult;
    }
}

TempAndRhData AHT20_GetTempAndRh()
{
    TempAndRhData SensorData;
    Wire.begin(12, 14);
    Wire.beginTransmission(0x38);
    Wire.write(0xAC);
    Wire.write(0x33);
    Wire.write(0x00);
    Wire.endTransmission();
    delay(100);
    Wire.beginTransmission(0x38);
    Wire.write(0x71);
    Wire.endTransmission();
    Wire.requestFrom(0x38, 6);
    byte state_code, RhMSB, RhCSB, RhLSBAndTempMSB, TempCSB, TempLSB;
    uint8_t tempuse; //临时存储，使用完毕后及时清零
    uint32_t RhData, TempData;
    RhData = 0;
    TempData = 0;
    state_code = Wire.read();
    RhMSB = Wire.read();
    RhCSB = Wire.read();
    RhLSBAndTempMSB = Wire.read();
    TempCSB = Wire.read();
    TempLSB = Wire.read();
    RhData = (((RhData | RhMSB) << 8) | RhCSB) << 4;
    tempuse = RhLSBAndTempMSB;
    tempuse = tempuse >> 4;
    RhData = RhData | tempuse;
    tempuse = 0;
    RhLSBAndTempMSB = RhLSBAndTempMSB << 4;
    RhLSBAndTempMSB = RhLSBAndTempMSB >> 4;
    TempData = ((((TempData | RhLSBAndTempMSB) << 8) | TempCSB) << 8) | TempLSB;
    /*
        if (bitRead(TempData, 19) == 1)
        {
            for (int i = 20; i <= 23; i++)
            {
                bitWrite(TempData, i, 1);
            }
        }
    */
    SensorData.Humidity = ((int)RhData / pow(2, 20)) * 100;
    SensorData.Temperature = ((int)TempData / pow(2, 20)) * 200 - 50;
    return SensorData;
}