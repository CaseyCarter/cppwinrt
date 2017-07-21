@echo off
setlocal 

call SetBuildVars.cmd %*

set compiler=%~dp0\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%~dp0\%BuildStaging%

%compiler% -in @Projection\SDKResponseFiles\Foundation.10.0.15063.0.rsp -verbose -out %output%

