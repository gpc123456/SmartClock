#include "HP203B.h"

short HP203B_Init(int OSR)
{
    Wire.begin(12, 14);
    delay(1);
    byte OSR_SET;

    switch (OSR)
    {
    case 128:
        OSR_SET = 0x54;
        break;
    case 256:
        OSR_SET = 0x50;
        break;
    case 512:
        OSR_SET = 0x4C;
        break;
    case 1024:
        OSR_SET = 0x48;
        break;
    case 2048:
        OSR_SET = 0x44;
        break;
    case 4096:
        OSR_SET = 0x40;
        break;
    }

    Wire.beginTransmission(0x76);
    Wire.write(OSR_SET);
    short InitResult = Wire.endTransmission();
    delay(5);
    return InitResult;
}

float HP203B_ReadAirPressure(int OSR)
{
    Wire.begin(12, 14);
    byte OSR_SET;

    switch (OSR)
    {
    case 128:
        OSR_SET = 0x54;
        break;
    case 256:
        OSR_SET = 0x50;
        break;
    case 512:
        OSR_SET = 0x4C;
        break;
    case 1024:
        OSR_SET = 0x48;
        break;
    case 2048:
        OSR_SET = 0x44;
        break;
    case 4096:
        OSR_SET = 0x40;
        break;
    }

    Wire.beginTransmission(0x76);
    Wire.write(OSR_SET);
    Wire.endTransmission();

    switch (OSR)
    {
    case 128:
        delay(5);
        break;
    case 256:
        delay(10);
        break;
    case 512:
        delay(20);
        break;
    case 1024:
        delay(37);
        break;
    case 2048:
        delay(70);
        break;
    case 4096:
        delay(150);
        break;
    }

    Wire.beginTransmission(0x76);
    Wire.write(0x30);
    Wire.endTransmission();

    Wire.requestFrom(0x76, 3);
    byte OUT_P_MSB, OUT_P_CSB, OUT_P_LSB;
    OUT_P_MSB = Wire.read();
    OUT_P_CSB = Wire.read();
    OUT_P_LSB = Wire.read();
    uint32_t presResult_HEX = 0;
    presResult_HEX = ((((presResult_HEX + OUT_P_MSB) << 8) | OUT_P_CSB) << 8) | OUT_P_LSB;
    float presResult = (float)presResult_HEX;
    presResult = presResult / 100.0;
    return presResult;
}
