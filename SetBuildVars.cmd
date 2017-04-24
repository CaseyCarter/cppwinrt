@echo off

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

set BuildStaging=%3
if "%BuildStaging%"=="" set BuildStaging=DevProjection
