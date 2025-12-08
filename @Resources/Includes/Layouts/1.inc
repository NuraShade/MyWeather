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
[Current_Weather_Condition_Icon]
Meter=Image 
MeasureName=Measure_Weather_Icon
ImageName=#@#Images\WeatherIcons\%1
X=((#Background_Width#-#Current_Weather_Condition_W#)/2*#Scale#)
Y=(15*#Scale#)
W=(#Current_Weather_Condition_W#*#Scale#)
H=(#Current_Weather_Condition_H#*#Scale#)
DynamicVariables=1
Container=ContentContainer

[Current_Temperature_Text]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
MeasureName2=Measure_Temperature_Unit
X=((#Background_Width#/2)*#Scale#)
Y=(120*#Scale#)r
Text=%1%2
FontFace=Samsung Sharp Sans
StringAlign=Center
MeterStyle=Text_Style