@echo off

call SetBuildVars %*

echo.
echo Executing Projection Unit Tests...
pushd %BuildStaging%\UnitTests
msbuild Tests.sln /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform%
call RunTests.cmd
popd
