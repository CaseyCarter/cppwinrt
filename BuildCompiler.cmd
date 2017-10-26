@echo off

call SetBuildVars.cmd %*

pushd cppwinrt

rem Clean target
rd %BuildPlatform%\%BuildConfiguration% /s /q >nul

echo Building compiler for %BuildConfiguration% %BuildPlatform%...
msbuild "cppwinrt.sln" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
set MsbuildErrorLevel=%ERRORLEVEL%

popd

if /i not "%BuildPlatform%" == "x86" goto :done
if /i not "%BuildConfiguration%" == "Release" goto :done
if %MsbuildErrorLevel%==0 copy %~dp0\cppwinrt\%BuildPlatform%\%BuildConfiguration%\cppwinrt.exe %BuildStaging%

:done
exit /B %MsbuildErrorLevel%
