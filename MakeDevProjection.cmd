@echo off
setlocal 

mkdir DevProjection >nul 2>&1
mklink /d /j DevProjection\Samples %~dp0\Projection\Samples >nul 2>&1
mklink /d /j DevProjection\UnitTests %~dp0\Projection\UnitTests >nul 2>&1
mklink /d /j DevProjection\SDKReferences %~dp0\Projection\SDKReferences >nul 2>&1
mklink DevProjection\cppwinrt.exe %~dp0cppwinrt\x86\Release\cppwinrt.exe >nul 2>&1

mkdir DevProjection\WinRT >nul 2>&1
md "%USERPROFILE%\My Documents\Visual Studio 2017\Visualizers" >nul 2>&1

rem see also: "%VSINSTALLDIR%\Common7\Packages\Debugger\Visualizers\"
mklink "%USERPROFILE%\My Documents\Visual Studio 2017\Visualizers\cppwinrt.natvis" %~dp0\DevProjection\WinRT\cppwinrt.natvis >nul 2>&1

echo Created DevProjection folder with symlinks to Samples, UnitTests, and Natvis