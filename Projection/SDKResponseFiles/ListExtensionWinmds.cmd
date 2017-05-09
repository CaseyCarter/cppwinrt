@echo off
setlocal 

if not %1.==. (
set Extension=%1
) else (
set Extension=WindowsDesktop
)

if not %2.==. (
set SdkVer=%2\
) else (
set SdkVer=%WindowsSDKVersion%
)

for /f delims^=^"^ tokens^=2^-4 %%i in ('findstr /C:"ApiContract " "%WindowsSdkDir%Extension SDKs\%Extension%\%SdkVer%SDKManifest.xml"') do @echo "%WindowsSdkDir%References\%SdkVer%%%i\%%k\%%i.winmd"
