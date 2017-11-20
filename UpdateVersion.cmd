@echo off

rem This script should only be executed for official builds

git checkout -f %BUILD_SOURCEBRANCHNAME%
if NOT "%ERRORLEVEL%"=="0" goto wrapup

echo.#pragma once > cppwinrt\source\version.h
echo.#define CPPWINRT_VERSION_STRING "%2" >> cppwinrt\source\version.h

if /i not "%BuildPlatform%" == "x86" goto :eof
if /i not "%BuildConfiguration%" == "Release" goto :eof

git add cppwinrt/source/version.h
if NOT "%ERRORLEVEL%"=="0" goto wrapup
git commit -m "Update for build %2"
if NOT "%ERRORLEVEL%"=="0" goto wrapup
REM Do no force push, if it fails just restart
git -c http.extraheader="AUTHORIZATION: bearer %1" push origin

:wrapup
exit /B %ERRORLEVEL%
