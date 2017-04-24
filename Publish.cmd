@echo off
setlocal

rem Script to publish build artifacts to \\redmond
rem This script does a conditional check to only publish for one Platform/Configuration (x86 Release)
rem Usage in TFS Build:
rem publish $(BuildPlatform) $(BuildConfiguration) "Projection" \\redmond\osg\Threshold\Tools\CORE\DEP\DART\CppForWinRT\$(Build.BuildNumber)

call SetBuildVars %*

set PublishShare=%4\%BuildPlatform%\%BuildConfiguration%
if /i not "%BuildPlatform%" == "x86" goto :skip
if /i not "%BuildConfiguration%" == "Release" goto :skip
goto :publish

:skip
echo Skipping publish for %BuildPlatform% %BuildConfiguration%
goto :eof

:publish
md %PublishShare%

pushd Projection\Samples 
git clean -d -f -x
popd

pushd Projection\UnitTests
git clean -d -f -x
popd

echo Publishing Compiler
for %%x in (exe pdb) do XCOPY CppWinRT\%BuildPlatform%\%BuildConfiguration%\*.%%x compiler /D /R /Y /J /I
powershell -ExecutionPolicy ByPass -Command "& '%cd%\zip.ps1' -directory '%cd%\compiler' -name 'compiler.zip'"
echo d | XCOPY compiler.zip %PublishShare% /D /R /Y /J 

echo Publish GitHub Format 
XCOPY %BuildStaging%\winrt stage\winrt /D /S /R /Y /J /I 
set PUBLIC_SAMPLES=AsyncReader Blocks CL IBuffer JustCoroutines Ocr Syndication Video XamlCode
for %%x in (%PUBLIC_SAMPLES%) do XCOPY Projection\Samples\%%x stage\Samples\%%x /D /S /R /Y /J /I 
powershell -ExecutionPolicy ByPass -Command "& '%cd%\zip.ps1' -directory '%cd%\stage' -name 'github.zip'"
echo d | XCOPY github.zip %PublishShare% /D /R /Y /J 

echo Publish Projection 
XCOPY Projection\Samples stage\Samples /D /S /R /Y /J /I 
XCOPY Projection\SDKReferences stage\SDKReferences /D /S /R /Y /J /I 
XCOPY Projection\SDKResponseFiles stage\SDKResponseFiles /D /S /R /Y /J /I 
XCOPY Projection\UnitTests stage\Tests /D /R /Y /J /I 
powershell -ExecutionPolicy ByPass -Command "& '%cd%\zip.ps1' -directory '%cd%\stage' -name 'projection.zip'"
echo d | XCOPY projection.zip %PublishShare% /D /R /Y /J 