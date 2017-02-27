@echo off

rem Script to build compiler front end and back end

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

call :Build FrontEnd
call :Build BackEnd
call Strings.bat
call :Build BackEnd
goto :eof

:Build 
pushd %1
rem echo. > BuildAllOutput.txt
echo Building all solutions for %BuildConfiguration% %BuildPlatform%...
for /f %%i in ('dir /s /b *.sln') do pushd "%%~pi" & msbuild "%%~ni.sln" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% & popd
rem 2>&1 >>BuildAllOutput.txt
popd 
goto :eof
