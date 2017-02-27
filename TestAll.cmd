@echo off

rem Script to run front end and projection unit tests

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

call TestFrontEnd %BuildPlatform% %BuildConfiguration%
call TestProjection %BuildPlatform% %BuildConfiguration%
