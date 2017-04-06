setlocal ENABLEDELAYEDEXPANSION

echo off

if "%1" == "" goto :usage
if not exist "UWP.%1.rsp" goto :missing
if not exist "UWPPlusAllExtensions.%1.rsp" goto :missing

for /F "tokens=1,* usebackq" %%G in (UWPPlusAllExtensions.%1.rsp) do (
    for /F "tokens=6-9 delims=\" %%P in ("%%H") do (
        mkdir ..\SDKReferences\%%Q\%%R
        copy %%H ..\SDKReferences\%%Q\%%R
    )
)

copy UWP.%1.rsp ..\SDKResponseFiles
copy UWPPlusAllExtensions.%1.rsp ..\SDKResponseFiles

goto :eof

:usage
echo Usage: IntegrateReferencesIntoOfficial.cmd sdkver
goto :eof

:missing
echo Files UWP.%1.rsp and UWPPlusAllExtensions.%1.rsp must exist
goto :eof