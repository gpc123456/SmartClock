#include "Vibration.h"

void Vibration(short VibrationTimeMs, short RepeatTimes, short IntervalTimeMs)
{
    pinMode(16, OUTPUT);
    for (short i = 0; i < RepeatTimes;)
    {
        digitalWrite(16, 0);
        delay(VibrationTimeMs);
        digitalWrite(16, 1);
        i++;
        if (i == RepeatTimes)
        {
            break;
        }
        delay(IntervalTimeMs);
    }
}