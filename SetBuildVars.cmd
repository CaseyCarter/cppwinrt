@echo off

set BuildPlatform=%1
if "%BuildPlatform%"=="" set BuildPlatform=x86

set BuildConfiguration=%2
if "%BuildConfiguration%"=="" set BuildConfiguration=Release

set BuildStaging=%3
if "%BuildStaging%"=="" set BuildStaging=DevProjection

rem Ensure that every build script has VS environment set up for CL.exe, msbuild.exe, etc.
rem The path below is enforced via the VSO build demand, "VisualStudio_15.0".

pushd c:
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\VsDevCmd.bat" >nul 2>&1
popd
