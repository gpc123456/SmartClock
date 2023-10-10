#include "SmartClock.h"

bool UpdateWeather(WeatherData *weatherdata)
{
    WiFiClient wificlient;
    HTTPClient httpclient;

    // 建立http请求信息
    String httpRequest = "http://api.seniverse.com/v3/weather/daily.json?key=[YOURKEY]&location=ip&language=en";
    httpclient.begin(wificlient, httpRequest);

    // 尝试连接服务器
    if (httpclient.GET() == HTTP_CODE_OK)
    {
        Serial.println("Success!");
        String responsePayload = httpclient.getString();

        DynamicJsonDocument doc(1536);
        DeserializationError error = deserializeJson(doc, responsePayload);

        if (error)
        {
            Serial.print(F("deserializeJson() failed: "));
            Serial.println(error.f_str());
            return UPDATE_WEATHER_ERR;
        }

        JsonObject results_0 = doc["results"][0];
        JsonObject results_0_location = results_0["location"];

        strcpy(weatherdata->Location, results_0_location["name"]); // "City"
        short day_count = 0;
        for (JsonObject results_0_daily_item : results_0["daily"].as<JsonArray>())
        {
            strcpy(weatherdata->Date[day_count], results_0_daily_item["date"]);             // "2022-08-20", "2022-08-21", ...
            strcpy(weatherdata->code_day[day_count], results_0_daily_item["code_day"]);     // "4", "9", "11"
            strcpy(weatherdata->code_night[day_count], results_0_daily_item["code_night"]); // "4", "9", "13"
            strcpy(weatherdata->temp_high[day_count], results_0_daily_item["high"]);        // "29", "33", "32"
            strcpy(weatherdata->temp_low[day_count], results_0_daily_item["low"]);          // "22", "22", "23"
            strcpy(weatherdata->pRainfall[day_count], results_0_daily_item["precip"]);      // "0.00", "0.00", "0.68"
            day_count++;
        }
        weatherdata->DataAvailableTag = WDATA_AVAILABLE;
        weatherdata->UpdateTime = ReadTimeAndDate();

        httpclient.end();
        doc.clear();
        return UPDATE_WEATHER_SUCCESS;
    }
    else
    {
        Serial.println(" connection failed!");
        httpclient.end();
        return UPDATE_WEATHER_ERR;
    }
}

short FindWeatherData(WeatherData weatherdata, TimeAndDate timedata)
{
    //返回所查找日期天气在二维数组中第一维对应的数字(指针)
    // Standardization Date
    String s_year = String(timedata.year);
    char c_month[5];
    TransNumberToStandNumberChar(c_month, timedata.month);
    String s_month(c_month);
    char c_day[5];
    TransNumberToStandNumberChar(c_day, timedata.day);
    String s_day = String(c_day);
    String S_Today = s_year + "-" + s_month + "-" + s_day;
    short i;
    for (i = 0; i < 3; i++)
    {
        String day_weather = String(weatherdata.Date[i]);
        if (S_Today == day_weather)
        {
            break;
        }
    }
    return i; //返回3代表未找到指定日期的天气数据
}