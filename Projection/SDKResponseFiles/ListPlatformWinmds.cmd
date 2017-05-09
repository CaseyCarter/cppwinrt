@echo off
setlocal 

if not %1.==. (
set SdkVer=%1\
) else (
set SdkVer=%WindowsSDKVersion%
)

for /f delims^=^"^ tokens^=2^-4 %%i in ('findstr /C:"ApiContract " "%WindowsSdkDir%Platforms\UAP\%SdkVer%Platform.xml"') do @echo "%WindowsSdkDir%References\%SdkVer%%%i\%%k\%%i.winmd"
