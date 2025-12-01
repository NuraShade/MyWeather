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
;           Content
;=============================================================

[Round_Rectangle_Shape]
Meter=Shape 
X=(1*#Scale#)
Y=(32*#Scale#)
Shape=Rectangle 0,0,(#Background_Width#*#Scale#),((#Background_Height#*#Scale#)/1.5),(65*#Scale#) | StrokeWidth 0 | Rotate 140 | FillColor 178,217,178
DynamicVariables=1
Container=ContentContainer

; [Current_Temperature]
; Meter=String
; MeasureName=Measure_Current_Temperature_Rounded
; MeasureName2=Measure_Temperature_Unit
; X=((#Background_Width#/2)*#Scale#)
; Y=((#Background_Height#/2)*#Scale#)
; Text=%1%2  
; MeterStyle=Text_Style