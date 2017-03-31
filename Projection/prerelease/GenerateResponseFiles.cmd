setlocal ENABLEDELAYEDEXPANSION

echo off
echo Usage: GenerateResponseFiles.cmd ^<sdk_ver^>
echo.

if "%1" == "" (
    echo SDK version not specified. See usage.
    goto :eof
)

set KITVERSION=%1

if exist "%ProgramFiles(x86)%" (
    set KIT_ROOT="%ProgramFiles(x86)%\Windows Kits\10"
) else (
    set KIT_ROOT="%ProgramFiles%\Windows Kits\10"
)

if not exist %KIT_ROOT% (
     echo Could not find windows kits folder at %KIT_ROOT%
     goto :eof
)

set PLATDIR=%KIT_ROOT%\Platforms

REM For each directory in the Platforms folder
FOR /D %%D IN (%PLATDIR%\*) DO (

  set FOLDER="%%D"
  set OFILE="%%~nxD.rsp"
  CALL :ProcessExtensionFolder "%%D" %%~nxD %1
)

ECHO.
ECHO Now process all the Extension SDKs

SET EXTDIR=%KIT_ROOT%\"Extension SDKs"

REM For each directory in the SDK Extension folder
FOR /D %%D IN (%EXTDIR%\*) DO (

  set FOLDER="%%D"
  set OFILE="%%~nxD.rsp"
  CALL :ProcessExtensionFolder "%%D" %%~nxD %1
)

ECHO.
ECHO Combining response files and removing duplicate entries
type nul>complete_unsorted.tmp
for %%I in (*.rsp) DO (
    for /F "tokens=*" %%J in (%%I) do (
        set test=%%J
        set test=!test:"=""!
        find "!test!" complete_unsorted.tmp 1>nul

        if !errorlevel! NEQ 0 (
            echo %%J >> complete_unsorted.tmp
        )
    )
)

sort complete_unsorted.tmp > complete.tmp
erase /q complete_unsorted.tmp
if exist "UWPPlusAllExtensions.%1.rsp" erase UWPPlusAllExtensions.%1.rsp
if exist "UWP.%1.rsp" erase UWP.%1.rsp
rename complete.tmp UWPPlusAllExtensions.%1.rsp
rename UAP.rsp UWP.%1.rsp
goto :eof

:ProcessExtensionFolder
REM set FOLDER=%1
REM set OFILE=%2.rsp

IF EXIST %OFILE% DEL %OFILE%

set FOLDER=%FOLDER%\%KITVERSION%
set FOLDER=%FOLDER:"=%
SET MANIFEST="%FOLDER%\Platform.xml"

IF NOT EXIST %MANIFEST% (

    REM When Platform.xml does not exist, look for SDKManifest.xml
    SET MANIFEST="%FOLDER%\SDKManifest.xml"
    IF NOT EXIST !MANIFEST! (
        ECHO Neither Platform.xml nor SDKManifest.xml are present
        GOTO :EOF
    )
)

ECHO Generating response file for manifest: %MANIFEST%
FOR /F "tokens=1-3 usebackq" %%I IN ( %MANIFEST% ) DO (
    IF "%%I" EQU "<ApiContract" (
        SET NAME=%%J
        SET NAME=!NAME:~6!
        SET NAME=!NAME:~0, -1!
        SET VERSION=%%K
        SET VERSION=!VERSION:~9!
        SET VERSION=!VERSION:~0, -3!
        SET WINMD="C:\Program Files (x86)\Windows Kits\10\References\!KITVERSION!\!NAME!\!VERSION!\!NAME!.winmd"
        ECHO -winmd !WINMD!>> %OFILE%
    )
)

REM This goto :eof will pop control back to the for loop where this label was called, not exit the script.
goto :eof