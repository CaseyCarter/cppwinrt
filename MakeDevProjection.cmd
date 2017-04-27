@echo off
setlocal 

mkdir DevProjection >nul 2>&1
mklink /d DevProjection\Samples %~dp0\Projection\Samples >nul 2>&1
mklink /d DevProjection\UnitTests %~dp0\Projection\UnitTests >nul 2>&1
mklink /d DevProjection\SDKReferences %~dp0\Projection\SDKReferences >nul 2>&1
mkdir DevProjection\WinRT >nul 2>&1
mklink DevProjection\WinRT\ppl.h %~dp0\Projection\WinRT\ppl.h >nul 2>&1

echo Created DevProjection folder with symlinks to Samples and UnitTests
