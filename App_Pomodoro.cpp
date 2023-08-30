#include "SmartClock.h"

bool PomodoroFirstStartFlag;
uint32_t EndTime_Unix;
short OldRemainTime;
short NowPomodoroStatus;
short ContinuedTomatoTimes;

void App_Pomodoro(UBYTE *Canvas, short BatteryLevel, float NowTemp, short NowHumidity)
{
    if (PomodoroFirstStartFlag == POMODORO_FIRST_START)
    {
        WiFi.forceSleepBegin(0xFFFFFFF);
        delay(10);
        Vibration(100, 1);
        Pomodoro_StartPage();
        delay(1000);
        TimeAndDate Nowtime = ReadTimeAndDate();
        short TomatoNumber = GetTomatoNumber(Nowtime);
        UnixTime stamp(8);
        stamp.setDateTime(Nowtime.year, Nowtime.month, Nowtime.day, Nowtime.hour, Nowtime.minute, Nowtime.second);
        uint32_t unix = stamp.getUnix();
        EndTime_Unix = unix + 1500;
        OldRemainTime = 25;
        NowPomodoroStatus = STATUS_WORKING;
        Pomodoro_HomePage_FullRefresh(Canvas, Nowtime, BatteryLevel, NowPomodoroStatus, OldRemainTime, NowTemp, NowHumidity, TomatoNumber);
        ContinuedTomatoTimes = 0;
        PomodoroFirstStartFlag = POMODORO_NOFIRST_START;
    }
    else
    {
        TimeAndDate Nowtime = ReadTimeAndDate();
        UnixTime stamp(8);
        stamp.setDateTime(Nowtime.year, Nowtime.month, Nowtime.day, Nowtime.hour, Nowtime.minute, Nowtime.second);
        uint32_t NowUnix = stamp.getUnix();

        if (NowUnix >= EndTime_Unix)
        {
            WiFi.forceSleepBegin(0xFFFFFFF);
            delay(10);
            short TomatoNumber;
            if (NowPomodoroStatus == STATUS_WORKING && ContinuedTomatoTimes == 5 - 1)
            {
                EndTime_Unix = NowUnix + 1500;
                OldRemainTime = 25;
                NowPomodoroStatus = STATUS_REST_5;
                ContinuedTomatoTimes = 0;
                AddTomatoNumber(Nowtime, 1);
                TomatoNumber = GetTomatoNumber(Nowtime);
                Pomodoro_HomePage_FullRefresh(Canvas, Nowtime, BatteryLevel, NowPomodoroStatus, OldRemainTime, NowTemp, NowHumidity, TomatoNumber);
                Vibration(50, 2, 100);
            }
            else if (NowPomodoroStatus == STATUS_WORKING)
            {
                EndTime_Unix = NowUnix + 300;
                OldRemainTime = 5;
                NowPomodoroStatus = STATUS_REST_LESS5;
                ContinuedTomatoTimes++;
                AddTomatoNumber(Nowtime, 1);
                TomatoNumber = GetTomatoNumber(Nowtime);
                Pomodoro_HomePage_FullRefresh(Canvas, Nowtime, BatteryLevel, NowPomodoroStatus, OldRemainTime, NowTemp, NowHumidity, TomatoNumber);
                Vibration(50, 2, 100);
            }
            else if (NowPomodoroStatus == STATUS_REST_LESS5 || NowPomodoroStatus == STATUS_REST_5)
            {
                EndTime_Unix = NowUnix + 1500;
                OldRemainTime = 25;
                NowPomodoroStatus = STATUS_WORKING;
                Pomodoro_HomePage_PartRefresh_ExceptTomatoNumber(Canvas, Nowtime, BatteryLevel, NowPomodoroStatus, OldRemainTime, NowTemp, NowHumidity);
                Vibration(100, 1);
            }
        }

        short NowRemainTime = (EndTime_Unix - NowUnix) / 60 + 1;
        switch (NowPomodoroStatus)
        {
        case STATUS_WORKING:
            NowRemainTime = NowRemainTime > 25 ? 25 : NowRemainTime;
            break;
        case STATUS_REST_5:
            NowRemainTime = NowRemainTime > 25 ? 25 : NowRemainTime;
            break;
        case STATUS_REST_LESS5:
            NowRemainTime = NowRemainTime > 5 ? 5 : NowRemainTime;
            break;
        };

        if (NowRemainTime != OldRemainTime)
        {
            WiFi.forceSleepBegin(0xFFFFFFF);
            delay(10);
            Pomodoro_HomePage_PartRefresh_ExceptTomatoNumber(Canvas, Nowtime, BatteryLevel, NowPomodoroStatus, NowRemainTime, NowTemp, NowHumidity);
            OldRemainTime = NowRemainTime;
        }

        if (Direction() == FRONT_UP)
        {
            WiFi.forceSleepBegin(0xFFFFFFF);
            delay(10);
            Vibration(70, 2, 100);
            Pomodoro_ExitConfirm();
            while (true)
            {
                if (Shaking() == IS_SHAKING)
                {
                    ContinuedTomatoTimes = 0;
                    NowScreen = HOMEPAGE;
                    HomePageFirstDisplayTag = 0;
                    Vibration(100, 1);
                    break;
                }
                if (Direction() == FRONT_DOWN)
                {
                    Vibration(100, 1);
                    Nowtime = ReadTimeAndDate();
                    short TomatoNumber = GetTomatoNumber(Nowtime);
                    UnixTime stamp(8);
                    stamp.setDateTime(Nowtime.year, Nowtime.month, Nowtime.day, Nowtime.hour, Nowtime.minute, Nowtime.second);
                    uint32_t NowUnix = stamp.getUnix();

                    if (NowUnix >= EndTime_Unix)
                    {
                        if (NowPomodoroStatus == STATUS_WORKING && ContinuedTomatoTimes == 5 - 1)
                        {
                            EndTime_Unix = NowUnix + 1500;
                            OldRemainTime = 25;
                            NowPomodoroStatus = STATUS_REST_5;
                            ContinuedTomatoTimes = 0;
                            AddTomatoNumber(Nowtime, 1);
                        }
                        else if (NowPomodoroStatus == STATUS_WORKING)
                        {
                            EndTime_Unix = NowUnix + 300;
                            OldRemainTime = 5;
                            NowPomodoroStatus = STATUS_REST_LESS5;
                            ContinuedTomatoTimes++;
                            AddTomatoNumber(Nowtime, 1);
                        }
                        else if (NowPomodoroStatus == STATUS_REST_LESS5 || NowPomodoroStatus == STATUS_REST_5)
                        {
                            EndTime_Unix = NowUnix + 1500;
                            OldRemainTime = 25;
                            NowPomodoroStatus = STATUS_WORKING;
                        }
                    }
                    short OldRemainTime = (EndTime_Unix - NowUnix) / 60 + 1;
                    switch (NowPomodoroStatus)
                    {
                    case STATUS_WORKING:
                        OldRemainTime = OldRemainTime > 25 ? 25 : OldRemainTime;
                        break;
                    case STATUS_REST_5:
                        OldRemainTime = OldRemainTime > 25 ? 25 : OldRemainTime;
                        break;
                    case STATUS_REST_LESS5:
                        OldRemainTime = OldRemainTime > 5 ? 5 : OldRemainTime;
                        break;
                    };
                    Pomodoro_HomePage_FullRefresh(Canvas, Nowtime, BatteryLevel, NowPomodoroStatus, OldRemainTime, NowTemp, NowHumidity, TomatoNumber);
                    break;
                }
                delay(500);
            }
        }
    }
}