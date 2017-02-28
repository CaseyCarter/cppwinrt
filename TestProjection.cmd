@echo off

rem Script to run projection unit tests

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

echo.
echo Executing Projection Tests
pushd Projection\Tests
msbuild Tests.sln /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform%
call RunTests.cmd
popd
