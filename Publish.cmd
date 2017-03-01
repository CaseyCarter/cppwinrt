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
echo Publishing Back-end EXE and PDB Files
for %%x in (exe pdb) do XCOPY BackEnd\%BuildPlatform%\%BuildConfiguration%\*.%%x %PublishShare%\compiler /D /R /Y /J /I

echo Publishing Front-end EXE, DLLs, and PDB Files
for %%x in (dll exe pdb) do XCOPY FrontEnd\FrontEnd\bin\%BuildConfiguration%\*.%%x %PublishShare%\compiler /D /R /Y /J /I
XCOPY FrontEnd\FrontEnd\bin\%BuildConfiguration%\x86\*.dll %PublishShare%\compiler\x86 /D /R /Y /J /I

echo Publishing Projection 
XCOPY projection\Samples %PublishShare%\projection\Samples /D /S /R /Y /J /I 
XCOPY projection\SDKReferences %PublishShare%\projection\SDKReferences /D /S /R /Y /J /I 
XCOPY projection\SDKResponseFiles %PublishShare%\projection\SDKResponseFiles /D /S /R /Y /J /I 
XCOPY generated\Tests %PublishShare%\projection\Tests /D /R /Y /J /I 
rem XCOPY generated\winrt %PublishShare%\projection\winrt /D /S /R /Y /J /I 
XCOPY generated\*.zip %PublishShare%\projection /D /R /Y /J /I 

echo Publish GitHub Format 
set github=%PublishShare%\github_release\10.0.14393.0

rem Symlinks not supported over network?
goto :github_copy
md %github%
mklink /d %github%\winrt %PublishShare%\projection\winrt 
md %github%\Samples
mklink /d %github%\Samples\AsyncReader %PublishShare%\projection\Samples\AsyncReader
mklink /d %github%\Samples\Blocks %PublishShare%\projection\Samples\Blocks 
mklink /d %github%\Samples\CL %PublishShare%\projection\Samples\CL 
mklink /d %github%\Samples\JustCoroutines %PublishShare%\projection\Samples\JustCoroutines 
mklink /d %github%\Samples\Ocr %PublishShare%\projection\Samples\Ocr 
mklink /d %github%\Samples\Syndication %PublishShare%\projection\Samples\Syndication 
mklink /d %github%\Samples\Video %PublishShare%\projection\Samples\Video 
mklink /d %github%\Samples\XamlCode %PublishShare%\projection\Samples\XamlCode 

:github_copy
rem XCOPY generated\winrt %github%\winrt /D /S /R /Y /J /I 
XCOPY generated\*.zip %github% /D /R /Y /J /I 
for %%x in (AsyncReader Blocks CL JustCoroutines Ocr Syndication Video XamlCode) do XCOPY projection\Samples\%%x %github%\Samples\%%x /S /R /Y /J /I 
