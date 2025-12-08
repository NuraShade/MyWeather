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
;=============================================================
;           MeterStyles
;=============================================================
[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
FontSize=(25*#Scale#)
StringAlign=Left
StringCase=Upper
Antialias=1
DynamicVariables=1
Container=ContentContainer
;=============================================================
;           Measures
;=============================================================
@include_frostbehind_measure=#@#Includes\FrostBehindMeasure.inc
@include_current_forecast_measures=#@#Includes\WeatherMeasures\CurrentForecast.inc
;=============================================================
;           Content
;=============================================================
[Current_Time_Of_Day_Text]
Meter=String
MeasureName=Measure_Time_Of_Day
X=((#Background_Width#/2)*#Scale#)
Y=(10*#Scale#)
Text=%1
StringAlign=Center
MeterStyle=Text_Style

[Current_Weather_Condition_Icon]
Meter=Image 
MeasureName=Measure_Weather_Icon
ImageName=#@#Images\WeatherIcons\%1
X=(30*#Scale#)
Y=(40*#Scale#)
W=(#Current_Weather_Condition_W#*#Scale#)
H=(#Current_Weather_Condition_H#*#Scale#)
DynamicVariables=1
Container=ContentContainer

[Current_Temperature_Text]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
MeasureName2=Measure_Temperature_Unit
X=((#Background_Width#/2)*#Scale#)
Y=(60*#Scale#)
Text=%1%2
FontFace=Samsung Sharp Sans
FontSize=(50*#Scale#)
MeterStyle=Text_Style

[Current_Weather_Condition_Translated_Text]
Meter=String
MeasureName=Measure_Weather_Condition_Translated
Text=%1
X=(10*#Scale#)r
Y=(80*#Scale#)r
FontSize=(20*#Scale#)
MeterStyle=Text_Style