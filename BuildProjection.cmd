@echo off
setlocal 

call SetBuildVars %*

set compiler=%cd%\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%cd%\%BuildStaging%

%compiler% platform @Projection\SDKResponseFiles\UWP.10.0.15063.0.rsp -verbose -tests -out %output%
