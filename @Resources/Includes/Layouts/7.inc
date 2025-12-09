[Variables]
Is_Current_Forecast_Hourly=1
Data_Forecast_Shape_Y=235
Data_Forecast_Shape_W=65
Data_Forecast_Shape_H=150
Data_Forecast_Weather_Icon_W=50
Data_Forecast_Weather_Icon_H=50
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

[Data_Forecast_Top_Text_1_0]
Text=[Measure_Day1_Name_Abbreviated]
[Data_Forecast_Top_Text_1_1]
Text=[Measure_Hour1_Time_Abbreviated_Formatted_12H]
[Data_Forecast_Top_Text_2_0]
Text=[Measure_Day2_Name_Abbreviated]
[Data_Forecast_Top_Text_2_1]
Text=[Measure_Hour2_Time_Abbreviated_Formatted_12H]
[Data_Forecast_Top_Text_3_0]
Text=[Measure_Day3_Name_Abbreviated]
[Data_Forecast_Top_Text_3_1]
Text=[Measure_Hour3_Time_Abbreviated_Formatted_12H]
[Data_Forecast_Top_Text_4_0]
Text=[Measure_Day4_Name_Abbreviated]
[Data_Forecast_Top_Text_4_1]
Text=[Measure_Hour4_Time_Abbreviated_Formatted_12H]
[Data_Forecast_Top_Text_5_0]
Text=[Measure_Day5_Name_Abbreviated]
[Data_Forecast_Top_Text_5_1]
Text=[Measure_Hour5_Time_Abbreviated_Formatted_12H]

[Data_Forecast_Top_Text_Style]
X=((#Data_Forecast_Shape_W#*#Scale#)/2)r
Y=(10*#Scale#)r
StringAlign=Center

[Data_Forecast_Shape_Style]
Y=(#Data_Forecast_Shape_Y#*#Scale#)
Shape=Rectangle 0,0,(#Data_Forecast_Shape_W#*#Scale#),(#Data_Forecast_Shape_H#*#Scale#),4 | StrokeWidth 1 | StrokeColor 120,120,120 | FillColor #Data_Forecast_Shape_Color#,80
DynamicVariables=1
Container=ContentContainer

[Data_Forecast_Weather_Icon1_0]
MeasureName=Measure_Day1_Weather_Icon
[Data_Forecast_Weather_Icon1_1]
MeasureName=Measure_Hour1_Weather_Icon
[Data_Forecast_Weather_Icon2_0]
MeasureName=Measure_Day2_Weather_Icon
[Data_Forecast_Weather_Icon2_1]
MeasureName=Measure_Hour2_Weather_Icon
[Data_Forecast_Weather_Icon3_0]
MeasureName=Measure_Day3_Weather_Icon
[Data_Forecast_Weather_Icon3_1]
MeasureName=Measure_Hour3_Weather_Icon
[Data_Forecast_Weather_Icon4_0]
MeasureName=Measure_Day4_Weather_Icon
[Data_Forecast_Weather_Icon4_1]
MeasureName=Measure_Hour4_Weather_Icon
[Data_Forecast_Weather_Icon5_0]
MeasureName=Measure_Day5_Weather_Icon
[Data_Forecast_Weather_Icon5_1]
MeasureName=Measure_Hour5_Weather_Icon
;=============================================================
;           Measures
;=============================================================
@include_frostbehind_measure=#@#Includes\FrostBehindMeasure.inc
@include_current_forecast_measures=#@#Includes\WeatherMeasures\CurrentForecast.inc
@include_7days_forecast_measures=#@#Includes\WeatherMeasures\7DaysForecast.inc
@include_7hours_forecast_measures=#@#Includes\WeatherMeasures\7HoursForecast.inc
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

[Sun_Cycle_Text]
Meter=String
MeasureName=Measure_Day1_Sunrise_Formatted
MeasureName2=Measure_Day1_Sunset_12Hour
X=((#Background_Width#*#Scale#)-20*#Scale#)
Y=((-55*#Scale#) /2)r
StringAlign=Right
Text=Sunrise at %1 AM #CRLF#Sunset at %2
MeterStyle=Text_Style

[Daily_And_Hourly_Forecast_Toggle_Shape_0]
This=FillColor 0,0,0,0
That=FillColor #Daily_And_Hourly_Forecast_Toggle_Shape_Accent_Color#,70
[Daily_And_Hourly_Forecast_Toggle_Shape_1]
This=FillColor #Daily_And_Hourly_Forecast_Toggle_Shape_Accent_Color#,70
That=FillColor 0,0,0,0

[Daily_And_Hourly_Forecast_Toggle_Shape]
Meter=Shape
X=(20*#Scale#)
Y=(180*#Scale#)
Shape=Rectangle 0,0,(200*#Scale#),(40*#Scale#),4 | StrokeWidth 1 | StrokeColor #Daily_And_Hourly_Forecast_Toggle_Shape_Color# | FillColor #Daily_And_Hourly_Forecast_Toggle_Shape_Color#,50
Shape2=Rectangle 0,0,(100*#Scale#),(40*#Scale#),4 | StrokeWidth 0 | Extend This
Shape3=Rectangle 0,0,(100*#Scale#),(40*#Scale#),4 | StrokeWidth 0 | Extend That | Offset (100*#Scale#),0
MeterStyle=Daily_And_Hourly_Forecast_Toggle_Shape_#Is_Current_Forecast_Hourly#
DynamicVariables=1
Container=ContentContainer

[Hourly_Forecast_Text]
Meter=String
Text=Hourly 
X=(50*#Scale#)r
Y=(20*#Scale#)r
W=(100*#Scale#)
H=(40*#Scale#)
StringAlign=CenterCenter
MeterStyle=Text_Style
LeftMouseUpAction=[!SetVariable Is_Current_Forecast_Hourly 1][!WriteKeyValue Variables Is_Current_Forecast_Hourly 1 "#@#Includes\Layouts\7.inc"][!UpdateMeter *][!Redraw]

[Daily_Forecast_Text]
Meter=String
Text=Daily 
X=R
Y=r
W=(100*#Scale#)
H=(40*#Scale#)
StringAlign=CenterCenter
MeterStyle=Text_Style
LeftMouseUpAction=[!SetVariable Is_Current_Forecast_Hourly 0][!WriteKeyValue Variables Is_Current_Forecast_Hourly 0 "#@#Includes\Layouts\7.inc"][!UpdateMeter *][!Redraw]

[Data_Forecast_Shape_1]
Meter=Shape
X=(20*#Scale#)
MeterStyle=Data_Forecast_Shape_Style
[Data_Forecast_Top_Text_1]
Meter=String
MeterStyle=Text_Style | Data_Forecast_Top_Text_Style | Data_Forecast_Top_Text_1_#Is_Current_Forecast_Hourly#

[Data_Forecast_Weather_Icon_Style]
ImageName=#@#Images\WeatherIcons\%1
X=(-(#Data_Forecast_Weather_Icon_W#*#Scale#)/2)r
Y=(30*#Scale#)r
W=(#Data_Forecast_Weather_Icon_W#*#Scale#)
H=(#Data_Forecast_Weather_Icon_H#*#Scale#)
DynamicVariables=1
Container=ContentContainer
[Data_Forecast_Weather_Icon1]
Meter=Image
MeterStyle=Data_Forecast_Weather_Icon_Style | Data_Forecast_Weather_Icon1_#Is_Current_Forecast_Hourly#

[Data_Forecast_Shape_2]
Meter=Shape
X=(95*#Scale#)
MeterStyle=Data_Forecast_Shape_Style
[Data_Forecast_Top_Text_2]
Meter=String
MeterStyle=Text_Style | Data_Forecast_Top_Text_Style | Data_Forecast_Top_Text_2_#Is_Current_Forecast_Hourly#
[Data_Forecast_Weather_Icon2]
Meter=Image
MeterStyle=Data_Forecast_Weather_Icon_Style | Data_Forecast_Weather_Icon2_#Is_Current_Forecast_Hourly#

[Data_Forecast_Shape_3]
Meter=Shape
X=(170*#Scale#)
MeterStyle=Data_Forecast_Shape_Style
[Data_Forecast_Top_Text_3]
Meter=String
MeterStyle=Text_Style | Data_Forecast_Top_Text_Style | Data_Forecast_Top_Text_3_#Is_Current_Forecast_Hourly#
[Data_Forecast_Weather_Icon3]
Meter=Image
MeterStyle=Data_Forecast_Weather_Icon_Style | Data_Forecast_Weather_Icon3_#Is_Current_Forecast_Hourly#

[Data_Forecast_Shape_4]
Meter=Shape
X=(245*#Scale#)
MeterStyle=Data_Forecast_Shape_Style
[Data_Forecast_Top_Text_4]
Meter=String
MeterStyle=Text_Style | Data_Forecast_Top_Text_Style | Data_Forecast_Top_Text_4_#Is_Current_Forecast_Hourly#
[Data_Forecast_Weather_Icon4]
Meter=Image
MeterStyle=Data_Forecast_Weather_Icon_Style | Data_Forecast_Weather_Icon4_#Is_Current_Forecast_Hourly#

[Data_Forecast_Shape_5]
Meter=Shape
X=(320*#Scale#)
MeterStyle=Data_Forecast_Shape_Style
[Data_Forecast_Top_Text_5]
Meter=String
MeterStyle=Text_Style | Data_Forecast_Top_Text_Style | Data_Forecast_Top_Text_5_#Is_Current_Forecast_Hourly#
[Data_Forecast_Weather_Icon5]
Meter=Image
MeterStyle=Data_Forecast_Weather_Icon_Style | Data_Forecast_Weather_Icon5_#Is_Current_Forecast_Hourly#
