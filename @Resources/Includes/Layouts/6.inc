;=============================================================
;           MeterStyles
;=============================================================
[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
FontSize=(20*#Scale#)
StringAlign=CenterCenter
Antialias=1
DynamicVariables=1
Container=ContentContainer
;=============================================================
;           Measures
;=============================================================
@include_current_forecast_measures=#@#Includes\WeatherMeasures\CurrentForecast.inc
;=============================================================
;           Content
;=============================================================
[Round_Rectangle_Shape_Background]
Meter=Shape 
Y=((((#Background_Height#*#Scale#)/2))/2)
Shape=Rectangle 0,0,(#Background_Width#*#Scale#),((#Background_Height#*#Scale#)/2),(50*#Scale#) | StrokeWidth 0  | FillColor #Round_Rectangle_Shape_Color#
DynamicVariables=1
Container=ContentContainer

[Weather_Icon_Ellipse_Shape]
Meter=Shape
X=(15*#Scale#)r 
Y=((((#Background_Height#*#Scale#)/2)-(60*#Scale#))/2)r
Shape=Rectangle 0,0,(60*#Scale#),(60*#Scale#),(60*#Scale#) | FillColor #Weather_Icon_Ellipse_Shape_Color# | StrokeWidth 0
DynamicVariables=1
Container=ContentContainer

[Current_Weather_Condition_Icon]
Meter=Image 
MeasureName=Measure_Weather_Icon
ImageName=#@#Images\WeatherIcons\%1
X=(((60*#Scale#)-(#Current_Weather_Condition_W#*#Scale#))/2)r
Y=(((60*#Scale#)-(#Current_Weather_Condition_H#*#Scale#))/2)r
W=(#Current_Weather_Condition_W#*#Scale#)
H=(#Current_Weather_Condition_H#*#Scale#)
DynamicVariables=1
Container=ContentContainer

[Current_Temperature_And_Current_Translated_Code_Text]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
MeasureName2=Measure_Temperature_Unit
MeasureName3=Measure_Weather_Condition_Translated
X=((#Background_Width#/1.5)*#Scale#)
Y=((#Background_Height#*#Scale#)/2)
W=((#Background_Width#/2)*#Scale#)
Text=%1%2#CRLF#%3
FontSize=(18*#Scale#)
MeterStyle=Text_Style
InlineSetting=Size | (12*#Scale#) 
InlinePattern=.*#CRLF#(.*)
InlineSetting2=Weight | 300
InlinePattern2=.*#CRLF#(.*)