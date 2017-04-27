@echo off
setlocal 

call SetBuildVars.cmd %*

set compiler=%~dp0\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%~dp0\%BuildStaging%

%compiler% platform @Projection\SDKResponseFiles\UWPPlusAllExtensions.10.0.14393.0.rsp -verbose -tests -out %output%
