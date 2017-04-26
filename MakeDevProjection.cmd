@echo off
setlocal 

mkdir DevProjection >nul 2>&1
mklink /d DevProjection\Samples %cd%\Projection\Samples >nul 2>&1
mklink /d DevProjection\UnitTests %cd%\Projection\UnitTests >nul 2>&1
mklink /d DevProjection\SDKReferences %cd%\Projection\SDKReferences >nul 2>&1
mkdir DevProjection\WinRT >nul 2>&1
mklink DevProjection\WinRT\ppl.h %cd%\Projection\WinRT\ppl.h >nul 2>&1

echo Created DevProjection folder with symlinks to Samples and UnitTests
