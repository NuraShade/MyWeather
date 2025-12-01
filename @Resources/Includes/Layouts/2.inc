;=============================================================
;           MeterStyles
;=============================================================
[Text_Style]
FontColor=#Font_Color#
FontFace=#Font_Face#
FontWeight=#Font_Weight#
FontSize=(45*#Scale#)
StringAlign=CenterCenter
StringCase=Upper
Antialias=1
DynamicVariables=1
Container=ContentContainer
;=============================================================
;           Measures
;=============================================================
@include_frostbehind_measure=#@#Includes\FrostBehindMeasure.inc
;=============================================================
;           Content
;=============================================================
[Current_Temperature]
Meter=String
MeasureName=Measure_Current_Temperature_Rounded
MeasureName2=Measure_Temperature_Unit
X=((#Background_Width#/2)*#Scale#)
Y=((#Background_Height#/2)*#Scale#)
Text=%1%2  
MeterStyle=Text_Style