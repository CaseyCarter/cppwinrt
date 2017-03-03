@echo off

rem Script to publish build artifacts to \\redmond
rem This script does a conditional check to only publish for one Platform/Configuration (x86 Release)
rem Usage in TFS Build:
rem publish $(BuildPlatform) $(BuildConfiguration) \\redmond\osg\Threshold\Tools\CORE\DEP\DART\CppForWinRT\$(Build.BuildNumber)

set BuildPlatform=%1
set BuildConfiguration=%2
set PublishShare=%3\%BuildPlatform%\%BuildConfiguration%
if /i not "%BuildPlatform%" == "x86" goto :skip
if /i not "%BuildConfiguration%" == "Release" goto :skip
goto :publish

:skip
echo Skipping publish for %BuildPlatform% %BuildConfiguration%
goto :eof

:publish
md %PublishShare%

echo Publishing Compiler
for %%x in (exe pdb) do XCOPY BackEnd\%BuildPlatform%\%BuildConfiguration%\*.%%x compiler /D /R /Y /J /I
for %%x in (dll exe pdb) do XCOPY FrontEnd\FrontEnd\bin\%BuildConfiguration%\*.%%x compiler /D /R /Y /J /I
XCOPY FrontEnd\FrontEnd\bin\%BuildConfiguration%\x86\*.dll compiler\x86 /D /R /Y /J /I
powershell -ExecutionPolicy ByPass -Command "& '%cd%\zip.ps1' -directory '%cd%\compiler' -name 'compiler.zip'"
XCOPY compiler.zip %PublishShare% /D /R /Y /J 

echo Publish GitHub Format 
XCOPY generated\winrt stage\winrt /D /S /R /Y /J /I 
set PUBLIC_SAMPLES=AsyncReader Blocks CL IBuffer JustCoroutines Ocr Syndication Video XamlCode
for %%x in (%PUBLIC_SAMPLES%) do XCOPY projection\Samples\%%x stage\Samples\%%x /D /S /R /Y /J /I 
powershell -ExecutionPolicy ByPass -Command "& '%cd%\zip.ps1' -directory '%cd%\stage' -name 'github.zip'"
XCOPY github.zip %PublishShare% /D /R /Y /J 

echo Publish Projection 
XCOPY projection\Samples stage\Samples /D /S /R /Y /J /I 
XCOPY projection\SDKReferences stage\SDKReferences /D /S /R /Y /J /I 
XCOPY projection\SDKResponseFiles stage\SDKResponseFiles /D /S /R /Y /J /I 
XCOPY projection\Tests stage\Tests /D /R /Y /J /I 
powershell -ExecutionPolicy ByPass -Command "& '%cd%\zip.ps1' -directory '%cd%\stage' -name 'projection.zip'"
XCOPY projection.zip %PublishShare% /D /R /Y /J 