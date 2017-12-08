@echo off
setlocal

rem Script to publish build artifacts to \\redmond
rem This script does a conditional check to only publish for one Platform/Configuration (x86 Release)
rem Usage in TFS Build:
rem publish $(BuildPlatform) $(BuildConfiguration) "Projection" \\redmond\osg\Threshold\Tools\CORE\DEP\DART\CppForWinRT\$(Build.BuildNumber)

call SetBuildVars.cmd %*

set PublishShare=%4\%BuildPlatform%\%BuildConfiguration%

echo Publish VSIX
XCOPY vsix\bin\%BuildConfiguration%\cppwinrt.vsix %PublishShare% /D /R /Y /J 

if /i not "%BuildPlatform%" == "x86" goto :skip
if /i not "%BuildConfiguration%" == "Release" goto :skip
goto :publish

:skip
echo Skipping publish for %BuildPlatform% %BuildConfiguration%
goto :eof

:publish
md %PublishShare%

echo Publishing Compiler
for %%x in (exe pdb) do XCOPY CppWinRT\%BuildPlatform%\%BuildConfiguration%\*.%%x compiler /D /R /Y /J /I
powershell -ExecutionPolicy ByPass -Command "& '%~dp0\zip.ps1' -directory '%~dp0\compiler' -name 'compiler.zip'"
echo d | XCOPY compiler.zip %PublishShare% /D /R /Y /J 

echo Publish GitHub distribution
XCOPY %BuildStaging%\winrt stage\winrt /D /S /R /Y /J /I 
set PUBLIC_SAMPLES=Blocks CL CustomBuffer Direct2D Interop JustCoroutines Ocr Syndication Video XamlCalendar XamlCode XamlMarkup
for %%x in (%PUBLIC_SAMPLES%) do XCOPY Projection\Samples\%%x stage\Samples\%%x /D /S /R /Y /J /I 
powershell -ExecutionPolicy ByPass -Command "& '%~dp0\zip.ps1' -directory '%~dp0\stage' -name 'github.zip'"
echo d | XCOPY github.zip %PublishShare% /D /R /Y /J 

echo Publish entire projection (github + remaining samples and unit tests)
XCOPY compiler stage /D /R /Y /J /I
XCOPY Projection\Samples stage\Samples /D /S /R /Y /J /I 
XCOPY Projection\UnitTests stage\Tests /D /R /Y /J /I 
powershell -ExecutionPolicy ByPass -Command "& '%~dp0\zip.ps1' -directory '%~dp0\stage' -name 'projection.zip'"
echo d | XCOPY projection.zip %PublishShare% /D /R /Y /J 
