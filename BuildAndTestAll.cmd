@echo off

rem Script to build compiler, projection, samples, and test

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

call BuildCompilers.cmd %BuildPlatform% %BuildConfiguration%
call Projection.bat
call TestAll.cmd %BuildPlatform% %BuildConfiguration%
call BuildSamples.cmd %BuildPlatform% %BuildConfiguration%
popd
