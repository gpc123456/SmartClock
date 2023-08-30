#include "SmartClock.h"

void HomePage_FullRefresh(UBYTE *Canvas, TimeAndDate TimeData, WeatherData weatherdata, float Temper, short Humidity, short Pressure, short BatteryLevel)
{
    TimeData = ReadTimeAndDate();
    DEV_Module_Init();
    EPD_2IN9_Init(FULL_REFRESH);
    EPD_2IN9_Clear();
    delay(500);
    Paint_NewImage(Canvas, EPD_2IN9_WIDTH, EPD_2IN9_HEIGHT, 270, WHITE);
    Paint_SelectImage(Canvas);
    Paint_Clear(WHITE);
    Paint_DrawBitMap(Image_HomePageBasic);

    // DrawTime
    char t_hour[5];
    char t_min[5];
    TransNumberToStandNumberChar(t_hour, TimeData.hour);
    TransNumberToStandNumberChar(t_min, TimeData.minute);
    // hour
    switch (t_hour[0])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    }
    switch (t_hour[1])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    }
    // point
    Paint_DrawImage(Num_Point, 17, 296 - (163 + 40 - 1), 64, 40);
    // minute
    switch (t_min[0])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    }
    switch (t_min[1])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    }

    // DrawWeather
    //在查找明日数据时，请传递今日日期，若返回指针为2说明无明日数据
    if (weatherdata.DataAvailableTag == WDATA_AVAILABLE)
    {
        if (TimeData.hour >= 21 && TimeData.hour <= 23)
        {
            short p_weatherdata = FindWeatherData(weatherdata, TimeData);
            if (p_weatherdata < 2)
            {
                p_weatherdata++;
                Paint_DrawImage(Tomorrow_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                String s_weather_code = String(weatherdata.code_day[p_weatherdata]);
                int weather_code = s_weather_code.toInt();
                switch (weather_code)
                {
                case 0:
                    Paint_DrawImage(WCode_0, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 1:
                    Paint_DrawImage(WCode_1, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 2:
                    Paint_DrawImage(WCode_2, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 3:
                    Paint_DrawImage(WCode_3, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 4:
                    Paint_DrawImage(WCode_4, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 5:
                    Paint_DrawImage(WCode_5, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 6:
                    Paint_DrawImage(WCode_6, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 7:
                    Paint_DrawImage(WCode_7, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 8:
                    Paint_DrawImage(WCode_8, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 9:
                    Paint_DrawImage(WCode_9, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 10:
                    Paint_DrawImage(WCode_10, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 11:
                    Paint_DrawImage(WCode_11, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 12:
                    Paint_DrawImage(WCode_12, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 13:
                    Paint_DrawImage(WCode_13, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 14:
                    Paint_DrawImage(WCode_14, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 15:
                    Paint_DrawImage(WCode_15, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 16:
                    Paint_DrawImage(WCode_16, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 17:
                    Paint_DrawImage(WCode_17, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 18:
                    Paint_DrawImage(WCode_18, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 19:
                    Paint_DrawImage(WCode_19, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 20:
                    Paint_DrawImage(WCode_20, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 21:
                    Paint_DrawImage(WCode_21, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 22:
                    Paint_DrawImage(WCode_22, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 23:
                    Paint_DrawImage(WCode_23, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 24:
                    Paint_DrawImage(WCode_24, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 25:
                    Paint_DrawImage(WCode_25, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 26:
                    Paint_DrawImage(WCode_26, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 27:
                    Paint_DrawImage(WCode_27, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 28:
                    Paint_DrawImage(WCode_28, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 29:
                    Paint_DrawImage(WCode_29, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 30:
                    Paint_DrawImage(WCode_30, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 31:
                    Paint_DrawImage(WCode_31, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 32:
                    Paint_DrawImage(WCode_32, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 33:
                    Paint_DrawImage(WCode_33, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 34:
                    Paint_DrawImage(WCode_34, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 35:
                    Paint_DrawImage(WCode_35, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 36:
                    Paint_DrawImage(WCode_36, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 37:
                    Paint_DrawImage(WCode_37, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 38:
                    Paint_DrawImage(WCode_38, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 99:
                    Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                }
                Paint_DrawString_EN(5, 74, weatherdata.temp_low[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_EN(27, 74, "~", &Font12, BLACK, WHITE);
                Paint_DrawString_EN(35, 74, weatherdata.temp_high[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_CN(57, 74, "℃", &Font12CN, BLACK, WHITE);
                Paint_DrawString_CN(5, 90, "降水", &Font12CN, BLACK, WHITE);
                String s_prainfall = String(weatherdata.pRainfall[p_weatherdata]);
                float f_prainfall = s_prainfall.toFloat();
                f_prainfall = f_prainfall * 100;
                int i_prainfall = f_prainfall;
                char c_pRainfall[5];
                itoa(i_prainfall, c_pRainfall, 10);
                Paint_DrawString_EN(39, 90, c_pRainfall, &Font12, BLACK, WHITE);
                Paint_DrawString_EN(60, 90, "%", &Font12, BLACK, WHITE);
            }
            else
            {
                Paint_DrawImage(Tomorrow_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
            }
        }
        else
        {
            short p_weatherdata = FindWeatherData(weatherdata, TimeData);
            if (p_weatherdata < 3)
            {
                Paint_DrawImage(Today_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                String s_weather_code;
                if (TimeData.hour >= 19 && TimeData.hour < 21)
                {
                    s_weather_code = String(weatherdata.code_night[p_weatherdata]);
                }
                else
                {
                    s_weather_code = String(weatherdata.code_day[p_weatherdata]);
                }
                int weather_code = s_weather_code.toInt();
                switch (weather_code)
                {
                case 0:
                    Paint_DrawImage(WCode_0, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 1:
                    Paint_DrawImage(WCode_1, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 2:
                    Paint_DrawImage(WCode_2, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 3:
                    Paint_DrawImage(WCode_3, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 4:
                    Paint_DrawImage(WCode_4, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 5:
                    Paint_DrawImage(WCode_5, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 6:
                    Paint_DrawImage(WCode_6, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 7:
                    Paint_DrawImage(WCode_7, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 8:
                    Paint_DrawImage(WCode_8, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 9:
                    Paint_DrawImage(WCode_9, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 10:
                    Paint_DrawImage(WCode_10, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 11:
                    Paint_DrawImage(WCode_11, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 12:
                    Paint_DrawImage(WCode_12, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 13:
                    Paint_DrawImage(WCode_13, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 14:
                    Paint_DrawImage(WCode_14, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 15:
                    Paint_DrawImage(WCode_15, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 16:
                    Paint_DrawImage(WCode_16, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 17:
                    Paint_DrawImage(WCode_17, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 18:
                    Paint_DrawImage(WCode_18, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 19:
                    Paint_DrawImage(WCode_19, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 20:
                    Paint_DrawImage(WCode_20, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 21:
                    Paint_DrawImage(WCode_21, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 22:
                    Paint_DrawImage(WCode_22, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 23:
                    Paint_DrawImage(WCode_23, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 24:
                    Paint_DrawImage(WCode_24, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 25:
                    Paint_DrawImage(WCode_25, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 26:
                    Paint_DrawImage(WCode_26, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 27:
                    Paint_DrawImage(WCode_27, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 28:
                    Paint_DrawImage(WCode_28, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 29:
                    Paint_DrawImage(WCode_29, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 30:
                    Paint_DrawImage(WCode_30, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 31:
                    Paint_DrawImage(WCode_31, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 32:
                    Paint_DrawImage(WCode_32, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 33:
                    Paint_DrawImage(WCode_33, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 34:
                    Paint_DrawImage(WCode_34, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 35:
                    Paint_DrawImage(WCode_35, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 36:
                    Paint_DrawImage(WCode_36, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 37:
                    Paint_DrawImage(WCode_37, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 38:
                    Paint_DrawImage(WCode_38, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 99:
                    Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                }
                Paint_DrawString_EN(5, 74, weatherdata.temp_low[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_EN(27, 74, "~", &Font12, BLACK, WHITE);
                Paint_DrawString_EN(35, 74, weatherdata.temp_high[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_CN(57, 74, "℃", &Font12CN, BLACK, WHITE);
                Paint_DrawString_CN(5, 90, "降水", &Font12CN, BLACK, WHITE);
                String s_prainfall = String(weatherdata.pRainfall[p_weatherdata]);
                float f_prainfall = s_prainfall.toFloat();
                f_prainfall = f_prainfall * 100;
                int i_prainfall = f_prainfall;
                char c_pRainfall[5];
                itoa(i_prainfall, c_pRainfall, 10);
                Paint_DrawString_EN(39, 90, c_pRainfall, &Font12, BLACK, WHITE);
                Paint_DrawString_EN(60, 90, "%", &Font12, BLACK, WHITE);
            }
            else
            {
                Paint_DrawImage(Today_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
            }
        }
    }
    else
    {
        Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
    }

    // DrawTemp
    char c_temp[10];
    String s_temp = String(Temper, 1);
    strcpy(c_temp, s_temp.c_str());
    short temp_str_len = strlen(c_temp);
    Paint_DrawString_EN(30, 112, c_temp, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(30 + temp_str_len * 11 + 1, 114, "℃", &Font12CN, BLACK, WHITE);

    // DrawHumidity
    char c_humidity[5];
    itoa(Humidity, c_humidity, 10);
    short hum_str_len = strlen(c_humidity);
    Paint_DrawString_EN(125, 112, c_humidity, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(125 + hum_str_len * 11 + 1, 112, "%", &Font16, BLACK, WHITE);

    // DrawPressure
    char c_pressure[10];
    itoa(Pressure, c_pressure, 10);
    short pres_str_len = strlen(c_pressure);
    Paint_DrawString_EN(214, 112, c_pressure, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(214 + pres_str_len * 11 + 1, 112, "hPa", &Font16, BLACK, WHITE);

    // DrawDateAndWeek
    char c_year[10];
    char c_month[5];
    char c_day[5];
    itoa(TimeData.year, c_year, 10);
    TransNumberToStandNumberChar(c_month, TimeData.month);
    TransNumberToStandNumberChar(c_day, TimeData.day);
    Paint_DrawString_EN(95, 88, c_year, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(140, 88, "年", &Font12CN, BLACK, WHITE);
    Paint_DrawString_EN(153, 88, c_month, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(176, 88, "月", &Font12CN, BLACK, WHITE);
    Paint_DrawString_EN(189, 88, c_day, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(212, 88, "日", &Font12CN, BLACK, WHITE);
    Paint_DrawString_CN(232, 88, "星", &Font12CN, BLACK, WHITE);
    Paint_DrawString_CN(245, 88, "期", &Font12CN, BLACK, WHITE);
    switch (TimeData.weekday)
    {
    case 1:
        Paint_DrawString_CN(258, 88, "一", &Font12CN, BLACK, WHITE);
        break;
    case 2:
        Paint_DrawString_CN(258, 88, "二", &Font12CN, BLACK, WHITE);
        break;
    case 3:
        Paint_DrawString_CN(258, 88, "三", &Font12CN, BLACK, WHITE);
        break;
    case 4:
        Paint_DrawString_CN(258, 88, "四", &Font12CN, BLACK, WHITE);
        break;
    case 5:
        Paint_DrawString_CN(258, 88, "五", &Font12CN, BLACK, WHITE);
        break;
    case 6:
        Paint_DrawString_CN(258, 88, "六", &Font12CN, BLACK, WHITE);
        break;
    case 7:
        Paint_DrawString_CN(258, 88, "天", &Font12CN, BLACK, WHITE);
        break;
    }

    // DrawBatteryLevel
    switch (BatteryLevel)
    {
    case 4:
        Paint_DrawImage(BatteryIcon_4, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 3:
        Paint_DrawImage(BatteryIcon_3, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 2:
        Paint_DrawImage(BatteryIcon_2, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 1:
        Paint_DrawImage(BatteryIcon_1, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 0:
        Paint_DrawImage(BatteryIcon_0, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    }

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}

void HomePage_PartRefreshTime_Temperature_Humidity_Airpressure_Battery(UBYTE *Canvas, TimeAndDate TimeData, float temperature, short humidity, short airpressure, short batterylevel)
{
    DEV_Module_Init();
    EPD_2IN9_Init(PART_REFRESH);

    Paint_SelectImage(Canvas);
    char t_hour[5];
    char t_min[5];
    TransNumberToStandNumberChar(t_hour, TimeData.hour);
    TransNumberToStandNumberChar(t_min, TimeData.minute);
    
    // DrawTime
    Paint_ClearWindows(80, 16, 286, 82, WHITE);
    // hour
    switch (t_hour[0])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (81 + 40 - 1), 64, 40);
        break;
    }
    switch (t_hour[1])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (122 + 40 - 1), 64, 40);
        break;
    }
    // point
    Paint_DrawImage(Num_Point, 17, 296 - (163 + 40 - 1), 64, 40);
    // minute
    switch (t_min[0])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (204 + 40 - 1), 64, 40);
        break;
    }
    switch (t_min[1])
    {
    case '0':
        Paint_DrawImage(Num_0, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '1':
        Paint_DrawImage(Num_1, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '2':
        Paint_DrawImage(Num_2, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '3':
        Paint_DrawImage(Num_3, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '4':
        Paint_DrawImage(Num_4, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '5':
        Paint_DrawImage(Num_5, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '6':
        Paint_DrawImage(Num_6, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '7':
        Paint_DrawImage(Num_7, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '8':
        Paint_DrawImage(Num_8, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    case '9':
        Paint_DrawImage(Num_9, 17, 296 - (245 + 40 - 1), 64, 40);
        break;
    }

    // DrawTemp
    Paint_ClearWindows(27, 108, 103, 128, WHITE);
    char c_temp[10];
    String s_temp = String(temperature, 1);
    strcpy(c_temp, s_temp.c_str());
    short temp_str_len = strlen(c_temp);
    Paint_DrawString_EN(30, 112, c_temp, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(30 + temp_str_len * 11 + 1, 114, "℃", &Font12CN, BLACK, WHITE);

    // DrawHumidity
    Paint_ClearWindows(124, 108, 180, 128, WHITE);
    char c_humidity[5];
    itoa(humidity, c_humidity, 10);
    short hum_str_len = strlen(c_humidity);
    Paint_DrawString_EN(125, 112, c_humidity, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(125 + hum_str_len * 11 + 1, 112, "%", &Font16, BLACK, WHITE);

    // DrawPressure
    Paint_ClearWindows(213, 108, 296, 128, WHITE);
    char c_pressure[10];
    itoa(airpressure, c_pressure, 10);
    short pres_str_len = strlen(c_pressure);
    Paint_DrawString_EN(214, 112, c_pressure, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(214 + pres_str_len * 11 + 1, 112, "hPa", &Font16, BLACK, WHITE);

    // DrawDateAndWeek
    Paint_ClearWindows(93,86,272,104,WHITE);
    char c_year[10];
    char c_month[5];
    char c_day[5];
    itoa(TimeData.year, c_year, 10);
    TransNumberToStandNumberChar(c_month, TimeData.month);
    TransNumberToStandNumberChar(c_day, TimeData.day);
    Paint_DrawString_EN(95, 88, c_year, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(140, 88, "年", &Font12CN, BLACK, WHITE);
    Paint_DrawString_EN(153, 88, c_month, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(176, 88, "月", &Font12CN, BLACK, WHITE);
    Paint_DrawString_EN(189, 88, c_day, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(212, 88, "日", &Font12CN, BLACK, WHITE);
    Paint_DrawString_CN(232, 88, "星", &Font12CN, BLACK, WHITE);
    Paint_DrawString_CN(245, 88, "期", &Font12CN, BLACK, WHITE);
    switch (TimeData.weekday)
    {
    case 1:
        Paint_DrawString_CN(258, 88, "一", &Font12CN, BLACK, WHITE);
        break;
    case 2:
        Paint_DrawString_CN(258, 88, "二", &Font12CN, BLACK, WHITE);
        break;
    case 3:
        Paint_DrawString_CN(258, 88, "三", &Font12CN, BLACK, WHITE);
        break;
    case 4:
        Paint_DrawString_CN(258, 88, "四", &Font12CN, BLACK, WHITE);
        break;
    case 5:
        Paint_DrawString_CN(258, 88, "五", &Font12CN, BLACK, WHITE);
        break;
    case 6:
        Paint_DrawString_CN(258, 88, "六", &Font12CN, BLACK, WHITE);
        break;
    case 7:
        Paint_DrawString_CN(258, 88, "天", &Font12CN, BLACK, WHITE);
        break;
    }

    // DrawBatteryLevel
    Paint_ClearWindows(279, 1, 296, 10, WHITE);
    switch (batterylevel)
    {
    case 4:
        Paint_DrawImage(BatteryIcon_4, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 3:
        Paint_DrawImage(BatteryIcon_3, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 2:
        Paint_DrawImage(BatteryIcon_2, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 1:
        Paint_DrawImage(BatteryIcon_1, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    case 0:
        Paint_DrawImage(BatteryIcon_0, 1, 296 - (280 + 16 - 1), 8, 16);
        break;
    }

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}

void HomePage_PartRefreshWeather(UBYTE *Canvas, WeatherData weatherdata, TimeAndDate TimeData)
{
    DEV_Module_Init();
    EPD_2IN9_Init(PART_REFRESH);

    Paint_SelectImage(Canvas);
    Paint_ClearWindows(0, 0, 69, 103, WHITE);
    // DrawWeather
    //在查找明日数据时，请传递今日日期，若返回指针为2说明无明日数据
    if (weatherdata.DataAvailableTag == WDATA_AVAILABLE)
    {
        if (TimeData.hour >= 21 && TimeData.hour <= 23)
        {
            short p_weatherdata = FindWeatherData(weatherdata, TimeData);
            if (p_weatherdata < 2)
            {
                p_weatherdata++;
                Paint_DrawImage(Tomorrow_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                String s_weather_code = String(weatherdata.code_day[p_weatherdata]);
                int weather_code = s_weather_code.toInt();
                switch (weather_code)
                {
                case 0:
                    Paint_DrawImage(WCode_0, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 1:
                    Paint_DrawImage(WCode_1, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 2:
                    Paint_DrawImage(WCode_2, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 3:
                    Paint_DrawImage(WCode_3, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 4:
                    Paint_DrawImage(WCode_4, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 5:
                    Paint_DrawImage(WCode_5, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 6:
                    Paint_DrawImage(WCode_6, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 7:
                    Paint_DrawImage(WCode_7, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 8:
                    Paint_DrawImage(WCode_8, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 9:
                    Paint_DrawImage(WCode_9, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 10:
                    Paint_DrawImage(WCode_10, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 11:
                    Paint_DrawImage(WCode_11, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 12:
                    Paint_DrawImage(WCode_12, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 13:
                    Paint_DrawImage(WCode_13, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 14:
                    Paint_DrawImage(WCode_14, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 15:
                    Paint_DrawImage(WCode_15, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 16:
                    Paint_DrawImage(WCode_16, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 17:
                    Paint_DrawImage(WCode_17, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 18:
                    Paint_DrawImage(WCode_18, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 19:
                    Paint_DrawImage(WCode_19, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 20:
                    Paint_DrawImage(WCode_20, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 21:
                    Paint_DrawImage(WCode_21, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 22:
                    Paint_DrawImage(WCode_22, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 23:
                    Paint_DrawImage(WCode_23, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 24:
                    Paint_DrawImage(WCode_24, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 25:
                    Paint_DrawImage(WCode_25, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 26:
                    Paint_DrawImage(WCode_26, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 27:
                    Paint_DrawImage(WCode_27, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 28:
                    Paint_DrawImage(WCode_28, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 29:
                    Paint_DrawImage(WCode_29, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 30:
                    Paint_DrawImage(WCode_30, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 31:
                    Paint_DrawImage(WCode_31, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 32:
                    Paint_DrawImage(WCode_32, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 33:
                    Paint_DrawImage(WCode_33, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 34:
                    Paint_DrawImage(WCode_34, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 35:
                    Paint_DrawImage(WCode_35, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 36:
                    Paint_DrawImage(WCode_36, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 37:
                    Paint_DrawImage(WCode_37, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 38:
                    Paint_DrawImage(WCode_38, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 99:
                    Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                }
                Paint_DrawString_EN(5, 74, weatherdata.temp_low[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_EN(27, 74, "~", &Font12, BLACK, WHITE);
                Paint_DrawString_EN(35, 74, weatherdata.temp_high[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_CN(57, 74, "℃", &Font12CN, BLACK, WHITE);
                Paint_DrawString_CN(5, 90, "降水", &Font12CN, BLACK, WHITE);
                String s_prainfall = String(weatherdata.pRainfall[p_weatherdata]);
                float f_prainfall = s_prainfall.toFloat();
                f_prainfall = f_prainfall * 100;
                int i_prainfall = f_prainfall;
                char c_pRainfall[5];
                itoa(i_prainfall, c_pRainfall, 10);
                Paint_DrawString_EN(39, 90, c_pRainfall, &Font12, BLACK, WHITE);
                Paint_DrawString_EN(60, 90, "%", &Font12, BLACK, WHITE);
            }
            else
            {
                Paint_DrawImage(Tomorrow_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
            }
        }
        else
        {
            short p_weatherdata = FindWeatherData(weatherdata, TimeData);
            if (p_weatherdata < 3)
            {
                Paint_DrawImage(Today_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                String s_weather_code;
                if (TimeData.hour >= 19 && TimeData.hour < 21)
                {
                    s_weather_code = String(weatherdata.code_night[p_weatherdata]);
                }
                else
                {
                    s_weather_code = String(weatherdata.code_day[p_weatherdata]);
                }
                int weather_code = s_weather_code.toInt();
                switch (weather_code)
                {
                case 0:
                    Paint_DrawImage(WCode_0, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 1:
                    Paint_DrawImage(WCode_1, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 2:
                    Paint_DrawImage(WCode_2, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 3:
                    Paint_DrawImage(WCode_3, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 4:
                    Paint_DrawImage(WCode_4, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 5:
                    Paint_DrawImage(WCode_5, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 6:
                    Paint_DrawImage(WCode_6, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 7:
                    Paint_DrawImage(WCode_7, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 8:
                    Paint_DrawImage(WCode_8, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 9:
                    Paint_DrawImage(WCode_9, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 10:
                    Paint_DrawImage(WCode_10, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 11:
                    Paint_DrawImage(WCode_11, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 12:
                    Paint_DrawImage(WCode_12, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 13:
                    Paint_DrawImage(WCode_13, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 14:
                    Paint_DrawImage(WCode_14, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 15:
                    Paint_DrawImage(WCode_15, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 16:
                    Paint_DrawImage(WCode_16, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 17:
                    Paint_DrawImage(WCode_17, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 18:
                    Paint_DrawImage(WCode_18, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 19:
                    Paint_DrawImage(WCode_19, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 20:
                    Paint_DrawImage(WCode_20, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 21:
                    Paint_DrawImage(WCode_21, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 22:
                    Paint_DrawImage(WCode_22, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 23:
                    Paint_DrawImage(WCode_23, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 24:
                    Paint_DrawImage(WCode_24, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 25:
                    Paint_DrawImage(WCode_25, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 26:
                    Paint_DrawImage(WCode_26, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 27:
                    Paint_DrawImage(WCode_27, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 28:
                    Paint_DrawImage(WCode_28, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 29:
                    Paint_DrawImage(WCode_29, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 30:
                    Paint_DrawImage(WCode_30, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 31:
                    Paint_DrawImage(WCode_31, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 32:
                    Paint_DrawImage(WCode_32, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 33:
                    Paint_DrawImage(WCode_33, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 34:
                    Paint_DrawImage(WCode_34, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 35:
                    Paint_DrawImage(WCode_35, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 36:
                    Paint_DrawImage(WCode_36, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 37:
                    Paint_DrawImage(WCode_37, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 38:
                    Paint_DrawImage(WCode_38, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                case 99:
                    Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
                    break;
                }
                Paint_DrawString_EN(5, 74, weatherdata.temp_low[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_EN(27, 74, "~", &Font12, BLACK, WHITE);
                Paint_DrawString_EN(35, 74, weatherdata.temp_high[p_weatherdata], &Font12, BLACK, WHITE);
                Paint_DrawString_CN(57, 74, "℃", &Font12CN, BLACK, WHITE);
                Paint_DrawString_CN(5, 90, "降水", &Font12CN, BLACK, WHITE);
                String s_prainfall = String(weatherdata.pRainfall[p_weatherdata]);
                float f_prainfall = s_prainfall.toFloat();
                f_prainfall = f_prainfall * 100;
                int i_prainfall = f_prainfall;
                char c_pRainfall[5];
                itoa(i_prainfall, c_pRainfall, 10);
                Paint_DrawString_EN(39, 90, c_pRainfall, &Font12, BLACK, WHITE);
                Paint_DrawString_EN(60, 90, "%", &Font12, BLACK, WHITE);
            }
            else
            {
                Paint_DrawImage(Today_CN, 1, 296 - (19 + 32 - 1), 16, 32);
                Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
            }
        }
    }
    else
    {
        Paint_DrawImage(WCode_99, 24, 296 - (10 + 50 - 1), 48, 50);
    }

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}

/*
void HomePage_PartRefreshTemperature(UBYTE *Canvas, float Temper)
{
    DEV_Module_Init();
    EPD_2IN9_Init(PART_REFRESH);

    Paint_SelectImage(Canvas);
    Paint_ClearWindows(27, 108, 103, 128, WHITE);

    // DrawTemp
    char c_temp[10];
    String s_temp = String(Temper, 1);
    strcpy(c_temp, s_temp.c_str());
    short temp_str_len = strlen(c_temp);
    Paint_DrawString_EN(30, 112, c_temp, &Font16, BLACK, WHITE);
    Paint_DrawString_CN(30 + temp_str_len * 11 + 1, 114, "℃", &Font12CN, BLACK, WHITE);

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}

void HomePage_PartRefreshHumidity(UBYTE *Canvas, short Humidity)
{
    DEV_Module_Init();
    EPD_2IN9_Init(PART_REFRESH);

    Paint_SelectImage(Canvas);
    Paint_ClearWindows(124, 108, 180, 128, WHITE);

    // DrawHumidity
    char c_humidity[5];
    itoa(Humidity, c_humidity, 10);
    short hum_str_len = strlen(c_humidity);
    Paint_DrawString_EN(125, 112, c_humidity, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(125 + hum_str_len * 11 + 1, 112, "%", &Font16, BLACK, WHITE);

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}

void HomePage_PartRefreshAirpressure(UBYTE *Canvas, short Pressure)
{
    DEV_Module_Init();
    EPD_2IN9_Init(PART_REFRESH);

    Paint_SelectImage(Canvas);
    Paint_ClearWindows(213, 108, 296, 128, WHITE);

    // DrawPressure
    char c_pressure[10];
    itoa(Pressure, c_pressure, 10);
    short pres_str_len = strlen(c_pressure);
    Paint_DrawString_EN(214, 112, c_pressure, &Font16, BLACK, WHITE);
    Paint_DrawString_EN(214 + pres_str_len * 11 + 1, 112, "hPa", &Font16, BLACK, WHITE);

    EPD_2IN9_Display(Canvas);
    EPD_2IN9_Sleep();
}
*/