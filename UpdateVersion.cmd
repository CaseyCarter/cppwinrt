@echo off

rem This script should only be executed for official builds

echo.#pragma once > cppwinrt\source\version.h
echo.#define CPPWINRT_VERSION_STRING "%2" >> cppwinrt\source\version.h

if /i not "%BuildPlatform%" == "x86" goto :eof
if /i not "%BuildConfiguration%" == "Release" goto :eof

git checkout %BUILD_SOURCEBRANCHNAME%
if NOT "%ERRORLEVEL%"=="0" goto wrapup
git reset --keep
if NOT "%ERRORLEVEL%"=="0" goto wrapup
git add cppwinrt/source/version.h
if NOT "%ERRORLEVEL%"=="0" goto wrapup
git commit -m "Update for build %2"
if NOT "%ERRORLEVEL%"=="0" goto wrapup
REM Force push since no one else should be changing this repo
git -c http.extraheader="AUTHORIZATION: bearer %1" push -f origin

:wrapup
exit /B %ERRORLEVEL%