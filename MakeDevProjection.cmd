@echo off
setlocal 

mkdir DevProjection >nul 2>&1
mklink /d DevProjection\Samples %~dp0\Projection\Samples >nul 2>&1
mklink /d DevProjection\UnitTests %~dp0\Projection\UnitTests >nul 2>&1
mklink /d DevProjection\SDKReferences %~dp0\Projection\SDKReferences >nul 2>&1
mkdir DevProjection\WinRT >nul 2>&1
md "%USERPROFILE%\My Documents\Visual Studio 2017\Visualizers" >nul 2>&1
mklink "%USERPROFILE%\My Documents\Visual Studio 2017\Visualizers\cppwinrt.natvis" %~dp0\DevProjection\WinRT\cppwinrt.natvis >nul 2>&1

echo Created DevProjection folder with symlinks to Samples, UnitTests, and Natvis
