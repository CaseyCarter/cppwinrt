@echo off
setlocal 

set BUILD_ERRORLEVEL=0
echo.
echo Warnings:
findstr /C:"): warning" %1
if not ERRORLEVEL 1 set BUILD_ERRORLEVEL=1
echo.
echo Errors:
findstr /C:"): error" %1
if not ERRORLEVEL 1 set BUILD_ERRORLEVEL=2
echo.
echo Fatal Errors:
findstr /C:"): fatal error" %1
if not ERRORLEVEL 1 set BUILD_ERRORLEVEL=3

exit /B %BUILD_ERRORLEVEL%