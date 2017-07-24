@echo off
setlocal 

call SetBuildVars.cmd %*

set compiler=%~dp0\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%~dp0\%BuildStaging%

rd %output% /S /Q
%compiler% -in @Projection\SDKResponseFiles\UWP.10.0.15063.0.rsp -verbose -tests -natvis -out %output%
