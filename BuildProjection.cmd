@echo off
setlocal 

call SetBuildVars.cmd %*

set compiler=%~dp0\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe
set output=%~dp0\%BuildStaging%

rd %output%\winrt /S /Q
%compiler% -in 10.0.15063.0 -verbose -tests -natvis -out %output%
