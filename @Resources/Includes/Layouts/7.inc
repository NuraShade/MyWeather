;=============================================================
;           MeterStyles
;=============================================================
[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
FontSize=(12*#Scale#)
Antialias=1
DynamicVariables=1
Container=ContentContainer
;=============================================================
;           Measures
;=============================================================
@include_frostbehind_measure=#@#Includes\FrostBehindMeasure.inc
@include_current_forecast_measures=#@#Includes\WeatherMeasures\CurrentForecast.inc
@include_7days_forecast_measures=#@#Includes\WeatherMeasures\7DaysForecast.inc
;=============================================================
;           Content
;=============================================================

[Current_City_And_Country_Text]
Meter=String
Text=Hasilpur,Lahore 
X=(20*#Scale#)
Y=(20*#Scale#)
MeterStyle=Text_Style

[Current_Weather_Condition_Icon]
Meter=Image 
; MeasureName=Measure_Weather_Icon
ImageName=#@#Images\WeatherIcons\ClearDay
X=(10*#Scale#)
Y=(60*#Scale#)
W=(#Current_Weather_Condition_W#*#Scale#)
H=(#Current_Weather_Condition_H#*#Scale#)
DynamicVariables=1
Container=ContentContainer

[Current_Temperature_Text]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
MeasureName2=Measure_Temperature_Unit
X=(120*#Scale#)
Y=((#Current_Weather_Condition_H#*#Scale#)/2)r 
StringAlign=LeftCenter
Text=%1%2  
FontFace=Samsung Sharp Sans
FontWeight=500
FontSize=(55*#Scale#)
MeterStyle=Text_Style
InlineSetting=Size | (12*#Scale#)
InlinePattern=[°][CF]

[Sunrise_Cycle_Text]
Meter=String
MeasureName=Measure_Day1_Sunrise_Formatted
X=((#Background_Width#*#Scale#)-20*#Scale#)
Y=((-55*#Scale#) /2)r
StringAlign=Right
Text=Sunrise at %1 AM
MeterStyle=Text_Style

[Sunset_Cycle_Text]
Meter=String
MeasureName=Measure_Day1_Sunset_12Hour
X=r
Y=R
StringAlign=Right
Text=Sunset  at  %1
MeterStyle=Text_Style