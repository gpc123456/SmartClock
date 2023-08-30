#include "SmartClock.h"

short GetTomatoNumber(TimeAndDate TimeData)
{
    if (LittleFS.begin())
    {
        String s_year = String(TimeData.year);
        String s_month = String(TimeData.month);
        String s_day = String(TimeData.day);
        String FileName = "/Tomato" + s_year + s_month + s_day;
        if (LittleFS.exists(FileName))
        {
            Serial.println(FileName);
            char FileData[5];
            File TomatoFile = LittleFS.open(FileName, "r");
            for (int i = 0; i < TomatoFile.size(); i++)
            {
                FileData[i] = (char)TomatoFile.read();
            }
            TomatoFile.close();
            String s_tomataonumber = String(FileData);
            short TomatoNumber;
            TomatoNumber = s_tomataonumber.toInt();
            return TomatoNumber;
        }
        else
        {
            LittleFS.format();
            File TomatoFile = LittleFS.open(FileName, "w");
            TomatoFile.println(0);
            TomatoFile.close();
            return 0;
        }
    }
    else
    {
        Serial.println("LittleFS Start Err!");
        return 999;
    }
}

void AddTomatoNumber(TimeAndDate TimeData, short WillAddTomatoNumber)
{
    if (LittleFS.begin())
    {
        String s_year = String(TimeData.year);
        String s_month = String(TimeData.month);
        String s_day = String(TimeData.day);
        String FileName = "/Tomato" + s_year + s_month + s_day;
        if (LittleFS.exists(FileName))
        {
            Serial.println(FileName);
            char FileData[5];
            File TomatoFile = LittleFS.open(FileName, "r");
            for (int i = 0; i < TomatoFile.size(); i++)
            {
                FileData[i] = (char)TomatoFile.read();
            }
            TomatoFile.close();
            String s_tomataonumber = String(FileData);
            short TomatoNumber;
            TomatoNumber = s_tomataonumber.toInt();
            TomatoNumber = TomatoNumber + WillAddTomatoNumber;
            TomatoFile = LittleFS.open(FileName, "w");
            TomatoFile.println(TomatoNumber);
            TomatoFile.close();
        }
        else
        {
            LittleFS.format();
            File TomatoFile = LittleFS.open(FileName, "w");
            TomatoFile.println(WillAddTomatoNumber);
            TomatoFile.close();
        }
    }
    else
    {
        Serial.println("LittleFS Start Err!");
    }
}