@echo off

rem Script to build all samples with current projection

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

pushd Projection\Samples

rem Clean targets
for /f %%i in ('dir /s /b %BuildConfiguration%') do @rd %%i /s /q >nul

echo. > BuildAllOutput.txt
echo Building all samples for %BuildConfiguration% %BuildPlatform%...
for /f %%i in ('dir /s /b *.sln') do @echo %%i & msbuild "%%i" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 2>&1 >>BuildAllOutput.txt

rem Dump build errors, warnings
echo.
echo Errors:
findstr /C:"): error" BuildAllOutput.txt
echo.
echo Warnings:
findstr /C:"): warning" BuildAllOutput.txt

popd