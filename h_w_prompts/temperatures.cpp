strComputer = "."
Set colTempProbe = GetObject("Winmgmts:"_
    & "{impersonationLevel=impersonate}!\\"_ 
    & strComputer & "\root\cimv2")._
    InstancesOf("Win32_TemperatureProbe")
Num = 0
For Each obj In colTempProbe
WScript.Echo   obj.Name & VBNewLine _
    & obj.DeviceID & VBNewLine _
    & obj.Status & VBNewLine _
    & obj.Resolution & VBNewLine _
    & obj.Tolerance & VBNewLine _
    & obj.Accuracy 
    Num = Num + 1
Next
If Num = 0 Then
WScript.Echo "No temperature probe data"
End If