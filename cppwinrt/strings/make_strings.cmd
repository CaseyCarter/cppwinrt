@echo off
rem Makes strings.h and strings.cpp from %strings_sources% (see below)
rem make_strings.cmd is 'built' based on custom build tool, 
rem and can also be manually executed from the project (Ctrl + F7).
setlocal ENABLEDELAYEDEXPANSION
set string_sources=%~dp0base\*, %~dp0write\*, %~dp0print\*
if "%1"=="h" goto :makeh
if "%1"=="cpp" goto :makecpp

rem Do dependency checking in script, since VS doesn't support wildcards.
rem If newest file found is strings.*, we're done
if "%1"=="dep" (
	dir /b /o-d %~dp0 | findstr /n . | findstr 1:strings\. >nul && goto :eof
)
echo Making strings.h... & call %0 h > %~dp0strings.h
echo Making strings.cpp... & call %0 cpp > %~dp0strings.cpp
goto :eof

:makeh
echo #pragma once
echo.
echo namespace cppwinrt::strings {
echo.
for %%i in (%string_sources%) do (
    rem Create character arrays 
    echo extern char const %%~ni[];
    echo.
)
echo }
goto :eof

:makecpp
rem The C++ compiler enforces two length restrictions on string literals:
rem 1. pre-concat strings are limited to 16380 bytes (error C2026)
rem 2. post-concat strings are limited to 65535 bytes (error C1091)
rem The 16380 byte restriction is addressed by embedding breaks and concatenating.
set max_string_len=16000
echo #include "pch.h"
echo.
echo namespace cppwinrt::strings {
echo.
for %%i in (%string_sources%) do (
    rem Use set/p trick to insert string fragment without line break
    <nul set/p=extern char const %%~ni[] = R^"xyz(
    if /i %%~zi LEQ %max_string_len% (
        rem If entire file is <= pre-concat limit, type it directly (faster)
        type %%i
    ) else (
        set file_offset=%max_string_len%
        rem Else, create map of file lines to byte offsets to insert concat breaks
        for /f "tokens=1,* delims=:" %%k in ('findstr /R /O ".*" %%i') do (
            if /i %%k GTR !file_offset! (
                set /a file_offset=!file_offset! + %max_string_len%
                setlocal DISABLEDELAYEDEXPANSION
                echo.%%l^)xyz^" R^"xyz^(
                endlocal
            ) else (
                setlocal DISABLEDELAYEDEXPANSION
                echo.%%l
                endlocal
            )
        )
    )
    echo ^)xyz^";
    echo.
)
echo }
goto :eof