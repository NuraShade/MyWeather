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

[Variables]
Which_Icon_Use_For_Current_Condition=NA
; ============================================================
; Open-Meteo Weather API - Temperature and Weather Code
; Fetches current temperature and weather condition code from Open-Meteo API
; API Documentation: https://open-meteo.com/en/docs
; ============================================================

[Measure_Weather_Parent]
Measure=WebParser
URL=https://api.open-meteo.com/v1/forecast?latitude=#Latitude#&longitude=#Longitude#&current=temperature_2m,weather_code&temperature_unit=#Temperature_Unit#&timezone=auto
RegExp=(?siU).*"current":\{.*"temperature_2m":([0-9.-]+),.*"weather_code":([0-9]+)
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