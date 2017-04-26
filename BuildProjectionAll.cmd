@echo off
setlocal 

call SetBuildVars %*

set compiler=%cd%\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%cd%\%BuildStaging%

%compiler% platform @Projection\SDKResponseFiles\UWPPlusAllExtensions.10.0.14393.0.rsp -verbose -tests -out %output%
