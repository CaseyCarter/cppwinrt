@echo off

rem Script to run front end unit tests

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

echo.
echo Executing Front End Tests
pushd FrontEnd\FrontEndTests\bin\%BuildConfiguration%
call vstest.console.exe FrontEndTests.dll /Platform:%BuildPlatform%
popd
