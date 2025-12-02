;=============================================================
;           MeterStyles
;=============================================================
[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
FontSize=(40*#Scale#)
StringAlign=Center
StringCase=Upper
Antialias=1
DynamicVariables=1
Container=ContentContainer
;=============================================================
;           Content
;=============================================================
[Round_Rectangle_Shape]
Meter=Shape 
X=(((#Background_Width#*#Scale#)-((#Background_Width#*#Scale#)/1.5))/2)
Y=0
Shape=Rectangle 0,0,((#Background_Width#*#Scale#)/1.5),(#Background_Height#*#Scale#),(65*#Scale#) | StrokeWidth 0  | FillColor #Round_Rectangle_Shape_Color#
DynamicVariables=1
Container=ContentContainer

[Current_Temperature_Text]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
X=(((#Background_Width#*#Scale#)/1.5)/2)r
Y=(40*#Scale#)
Text=%1
MeterStyle=Text_Style

[Current_Weather_Condition_Translated_Text]
Meter=String
MeasureName=Measure_Weather_Condition_Translated
Text=%1
X=r
Y=(80*#Scale#)r
W=((#Background_Width#*#Scale#)/1.5)
ClipString=1
FontSize=(14*#Scale#)
MeterStyle=Text_Style
StringCase=None