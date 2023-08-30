#include "STK8BA58.h"

short Init_STK8BA58()
{
    Wire.begin(12, 14);
    delay(5);
    Wire.beginTransmission(0x18);
    Wire.write(POWER_REG_ADDR);
    Wire.write(POWER_LOWPOWER_25MS);
    return (Wire.endTransmission());
}

float STK8BA58_ReadAcceleration_X()
{
    uint16_t X_data = 0;
    uint16_t TempData;

    Wire.begin(12, 14);

    //---------GET X_axis DATA---------//
    Wire.beginTransmission(0x18);
    Wire.write(XOUT_LSB);
    Wire.endTransmission();
    Wire.requestFrom(0x18, 1);
    X_data = Wire.read();
    // Serial.println(X_data, 2);
    X_data = X_data >> 4;

    Wire.beginTransmission(0x18);
    Wire.write(XOUT_MSB);
    Wire.endTransmission();
    Wire.requestFrom(0x18, 1);
    TempData = Wire.read();
    // Serial.println(TempData, 2);
    TempData = TempData << 4;
    X_data = X_data | TempData;
    TempData = 0;
    if (bitRead(X_data, 11) == 1)
    {
        bitWrite(X_data, 12, 1);
        bitWrite(X_data, 13, 1);
        bitWrite(X_data, 14, 1);
        bitWrite(X_data, 15, 1);
    }
    // Serial.println(X_data);
    if ((short)X_data >= 0)
    {
        return ((2 * 9.8) / 2047 * (short)X_data);
    }
    else
    {
        return ((2 * 9.8) / 2048 * (short)X_data);
    }
}

float STK8BA58_ReadAcceleration_Y()
{
    uint16_t Y_data = 0;
    uint16_t TempData;

    Wire.begin(12, 14);

    //---------GET Y_axis DATA---------//
    Wire.beginTransmission(0x18);
    Wire.write(YOUT_LSB);
    Wire.endTransmission();
    Wire.requestFrom(0x18, 1);
    Y_data = Wire.read();
    // Serial.println(Y_data, 2);
    Y_data = Y_data >> 4;

    Wire.beginTransmission(0x18);
    Wire.write(YOUT_MSB);
    Wire.endTransmission();
    Wire.requestFrom(0x18, 1);
    TempData = Wire.read();
    // Serial.println(TempData, 2);
    TempData = TempData << 4;
    Y_data = Y_data | TempData;
    TempData = 0;
    if (bitRead(Y_data, 11) == 1)
    {
        bitWrite(Y_data, 12, 1);
        bitWrite(Y_data, 13, 1);
        bitWrite(Y_data, 14, 1);
        bitWrite(Y_data, 15, 1);
    }
    if ((short)Y_data >= 0)
    {
        return ((2 * 9.8) / 2047 * (short)Y_data);
    }
    else
    {
        return ((2 * 9.8) / 2048 * (short)Y_data);
    }
}

float STK8BA58_ReadAcceleration_Z()
{
    uint16_t Z_data = 0;
    uint16_t TempData;

    Wire.begin(12, 14);

    //---------GET Z_axis DATA---------//
    Wire.beginTransmission(0x18);
    Wire.write(ZOUT_LSB);
    Wire.endTransmission();
    Wire.requestFrom(0x18, 1);
    Z_data = Wire.read();
    // Serial.println(Z_data, 2);
    Z_data = Z_data >> 4;

    Wire.beginTransmission(0x18);
    Wire.write(ZOUT_MSB);
    Wire.endTransmission();
    Wire.requestFrom(0x18, 1);
    TempData = Wire.read();
    // Serial.println(TempData, 2);
    TempData = TempData << 4;
    Z_data = Z_data | TempData;
    TempData = 0;
    if (bitRead(Z_data, 11) == 1)
    {
        bitWrite(Z_data, 12, 1);
        bitWrite(Z_data, 13, 1);
        bitWrite(Z_data, 14, 1);
        bitWrite(Z_data, 15, 1);
    }
    if ((short)Z_data >= 0)
    {
        return ((2 * 9.8) / 2047 * (short)Z_data);
    }
    else
    {
        return ((2 * 9.8) / 2048 * (short)Z_data);
    }
}