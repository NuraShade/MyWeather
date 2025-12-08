;=============================================================
;           MeterStyles
;=============================================================
[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
FontSize=(20*#Scale#)
StringAlign=LeftCenter
Antialias=1
DynamicVariables=1
Container=ContentContainer
;=============================================================
;           Measures
;=============================================================
@include_current_forecast_measures=#@#Includes\WeatherMeasures\CurrentForecast.inc
@include_7days_forecast_measures=#@#Includes\WeatherMeasures\7DaysForecast.inc
;=============================================================
;           Content
;=============================================================
[Round_Rectangle_Shape_Background]
Meter=Shape 
Shape=Rectangle 0,0,(#Background_Width#*#Scale#),(#Background_Height#*#Scale#),(30*#Scale#) | StrokeWidth 0  | FillColor #Round_Rectangle_Shape_Color#
DynamicVariables=1
Container=ContentContainer

; Top Shape (Short - Weather Icon & Condition)
[Current_Condition_And_Weather_Icon_Background]
Meter=Shape 
X=(10*#Scale#)
Y=(15*#Scale#)
Shape=Rectangle 0,0,((#Background_Width#*#Scale#)-20*#Scale#),(((#Background_Height#*#Scale#)-20*#Scale#)/3.2),(30*#Scale#) | StrokeWidth 0 | FillColor #Current_Condition_And_Weather_Icon_Background_Color#
DynamicVariables=1
Container=ContentContainer

[Current_Weather_Condition_Icon]
Meter=Image 
MeasureName=Measure_Weather_Icon
ImageName=#@#Images\WeatherIcons\%1
X=(5*#Scale#)r
Y=(((((#Background_Height#*#Scale#)-20*#Scale#)/3.2)-(#Current_Weather_Condition_H#*#Scale#))/2)r
W=(#Current_Weather_Condition_W#*#Scale#)
H=(#Current_Weather_Condition_H#*#Scale#)
DynamicVariables=1
Container=ContentContainer

[Current_Weather_Condition_Translated_Text]
Meter=String
MeasureName=Measure_Weather_Condition_Translated
Text=%1
X=(5*#Scale#)R
Y=((#Current_Weather_Condition_H#*#Scale#)/2)r
W=(160*#Scale#)
ClipString=1
MeterStyle=Text_Style

; Middle Shape (Tall - Current Temperature)
[Current_Temperature_Shape_Stroke]
Meter=Shape 
X=(10*#Scale#)
Y=(95*#Scale#)
Shape=Rectangle 0,0,((#Background_Width#*#Scale#)-20*#Scale#),(((#Background_Height#*#Scale#)-20*#Scale#)/3.8),(20*#Scale#) | StrokeWidth 2 | StrokeColor #Current_Temperature_Shape_Stroke_Color# | FillColor 0,0,0,0
DynamicVariables=1
Container=ContentContainer

[Current_Temperature_Text]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
X=(((#Background_Width#*#Scale#)-20*#Scale#)/2)r
Y=((((#Background_Height#*#Scale#)-20*#Scale#)/3.8)/2)r
Text=Currently its %1
StringAlign=CenterCenter
MeterStyle=Text_Style
InlineSetting=Size | (15*#Scale#)
InlinePattern=Currently its
InlineSetting2=Weight | 700 | Face | Samsung Sharp Sans
InlinePattern2=(?<=its ).*

; Bottom Shape (Short - Feels Like & Low Tonight)
[Feels_And_Low_Tonight_Temperature_Shape_Background]
Meter=Shape 
X=(10*#Scale#)
Y=(165*#Scale#)
Shape=Rectangle 0,0,((#Background_Width#*#Scale#)-20*#Scale#),(((#Background_Height#*#Scale#)-20*#Scale#)/3.2),(30*#Scale#) | StrokeWidth 0 | FillColor #Feels_And_Low_Tonight_Temperature_Shape_Background_Color#
DynamicVariables=1
Container=ContentContainer

[Feels_And_Low_Tonight_Temperature_Text]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
MeasureName2=Measure_Day1_Min_Temperature_Rounded
X=(((#Background_Width#*#Scale#)-20*#Scale#)/2)r
Y=((((#Background_Height#*#Scale#)-20*#Scale#)/3.2)/2)r
Text=Feels Like %1#CRLF#Low Tonight %2
FontSize=(15*#Scale#)
StringAlign=CenterCenter
FontWeight=900
MeterStyle=Text_Style
InlineSetting=Weight | 500
InlinePattern=Feels Like
InlineSetting2=Weight | 500
InlinePattern2=Low Tonight