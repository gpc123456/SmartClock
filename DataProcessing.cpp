#include "SmartClock.h"

void TransNumberToStandNumberChar(char CharType[5], short NumType)
{
    switch (NumType)
    {
    case 0:
        CharType[0] = '0';
        CharType[1] = '0';
        CharType[2] = '\0';
        break;
    case 1:
        CharType[0] = '0';
        CharType[1] = '1';
        CharType[2] = '\0';
        break;
    case 2:
        CharType[0] = '0';
        CharType[1] = '2';
        CharType[2] = '\0';
        break;
    case 3:
        CharType[0] = '0';
        CharType[1] = '3';
        CharType[2] = '\0';
        break;
    case 4:
        CharType[0] = '0';
        CharType[1] = '4';
        CharType[2] = '\0';
        break;
    case 5:
        CharType[0] = '0';
        CharType[1] = '5';
        CharType[2] = '\0';
        break;
    case 6:
        CharType[0] = '0';
        CharType[1] = '6';
        CharType[2] = '\0';
        break;
    case 7:
        CharType[0] = '0';
        CharType[1] = '7';
        CharType[2] = '\0';
        break;
    case 8:
        CharType[0] = '0';
        CharType[1] = '8';
        CharType[2] = '\0';
        break;
    case 9:
        CharType[0] = '0';
        CharType[1] = '9';
        CharType[2] = '\0';
        break;
    default:
        itoa(NumType, CharType, 10);
    }
}

float SimplifyTemperatureToOneDecimal(float rawdata)
{
    int i_temp = rawdata;
    float diffValue = rawdata - i_temp;
    diffValue = abs(diffValue);
    if (rawdata >= 0)
    {
        if (diffValue >= 0 && diffValue <= 0.25)
        {
            float f_result = i_temp;
            return f_result;
        }
        if (diffValue > 0.25 && diffValue < 0.75)
        {
            float f_result = i_temp + 0.5;
            return f_result;
        }
        if (diffValue >= 0.75)
        {
            float f_result = i_temp + 1;
           return f_result;
        }
    }
    if (rawdata < 0)
    {
        if (diffValue >= 0 && diffValue <= 0.25)
        {
            float f_result = i_temp;
            return f_result;
        }
        if (diffValue > 0.25 && diffValue < 0.75)
        {
            float f_result = i_temp - 0.5;
            return f_result;
        }
        if (diffValue >= 0.75)
        {
            float f_result = i_temp - 1;
            return f_result;
        }
    }
    return 0;
}
