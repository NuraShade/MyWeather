;============================================================
;  NuraShade Skin
;  Copyright (c) 2025 NuraShade
;
;  Licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
;  You are free to:
;    • Share — copy and redistribute the material in any medium or format
;    • Adapt — remix, transform, and build upon the material
;      for any purpose, even commercially.
;
;  Under the following terms:
;    • Attribution — You must give appropriate credit, provide a link to the license,
;      and indicate if changes were made.
;    • ShareAlike — If you remix, transform, or build upon the material,
;      you must distribute your contributions under the same license as the original.
;
;  License Details: https://creativecommons.org/licenses/by-sa/3.0/
;============================================================

; ============================================================
; Open-Meteo Weather API - Temperature, Weather Code, and Is Day
; Fetches current temperature, weather condition code, and day/night status from Open-Meteo API
; API Documentation: https://open-meteo.com/en/docs
; ============================================================

[Measure_Weather_Parent]
Measure=WebParser
URL=https://api.open-meteo.com/v1/forecast?latitude=#Latitude#&longitude=#Longitude#&current=temperature_2m,weather_code,is_day&temperature_unit=#Temperature_Unit#&timezone=auto
RegExp=(?siU).*"current":\{.*"temperature_2m":([0-9.-]+),.*"weather_code":([0-9]+),.*"is_day":([0-1])
UpdateRate=600
DynamicVariables=1

[Measure_Current_Temperature]
Measure=WebParser
URL=[Measure_Weather_Parent]
StringIndex=1
DynamicVariables=1

[Measure_Current_Temperature_Rounded]
Measure=Calc
Formula=Ceil([Measure_Current_Temperature])
DynamicVariables=1

[Measure_Current_Weather_Code]
Measure=WebParser
URL=[Measure_Weather_Parent]
StringIndex=2
DynamicVariables=1

[Measure_Is_Day]
Measure=WebParser
URL=[Measure_Weather_Parent]
StringIndex=3
DynamicVariables=1

[Measure_Weather_Condition_Translated]
Measure=Calc
Formula=[Measure_Current_Weather_Code]
RegExpSubstitute=1
Substitute="^0$":"Clear Sky","^1$":"Mainly Clear","^2$":"Partly Cloudy","^3$":"Overcast","^45$":"Fog","^48$":"Depositing Rime Fog","^51$":"Light Drizzle","^53$":"Moderate Drizzle","^55$":"Dense Drizzle","^56$":"Light Freezing Drizzle","^57$":"Dense Freezing Drizzle","^61$":"Slight Rain","^63$":"Moderate Rain","^65$":"Heavy Rain","^66$":"Light Freezing Rain","^67$":"Heavy Freezing Rain","^71$":"Slight Snow Fall","^73$":"Moderate Snow Fall","^75$":"Heavy Snow Fall","^77$":"Snow Grains","^80$":"Slight Rain Showers","^81$":"Moderate Rain Showers","^82$":"Violent Rain Showers","^85$":"Slight Snow Showers","^86$":"Heavy Snow Showers","^95$":"Thunderstorm","^96$":"Thunderstorm with Slight Hail","^99$":"Thunderstorm with Heavy Hail"
DynamicVariables=1

[Measure_Weather_Icon]
Measure=Calc
Formula=[Measure_Current_Weather_Code] + ([Measure_Is_Day] * 1000)
RegExpSubstitute=1
Substitute="^1000$":"ClearDay.png","^0$":"ClearNight.png","^1001$":"MainlyClearDay.png","^1$":"MainlyClearNight.png","^1002$":"PartlyCloudyDay.png","^2$":"PartlyCloudyNight.png","^(100)?3$":"Overcast.png","^104[58]$":"FoggyDay.png","^4[58]$":"FoggyNight.png","^(10)?5[135]$":"Drizzle.png","^(10)?5[67]$":"FreezingRain.png","^(10)?6[135]$":"Rain.png","^(10)?6[67]$":"FreezingRain.png","^(10)?7[1357]$":"Snow.png","^(10)?8[012]$":"Rain.png","^(10)?8[56]$":"Snow.png","^(10)?9[569]$":"ThunderStorm.png"
DynamicVariables=1