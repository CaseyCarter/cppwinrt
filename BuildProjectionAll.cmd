@echo off
setlocal 

call SetBuildVars.cmd %*

set compiler=%~dp0\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%~dp0\%BuildStaging%

%compiler% -i @Projection\SDKResponseFiles\UWPPlusAllExtensions.10.0.15063.0.rsp -v -t -n -o %output%
