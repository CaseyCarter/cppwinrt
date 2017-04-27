@echo off

call SetBuildVars.cmd %*

set test_output=%~dp0\RunUnitTests.output

echo Building Unit Tests...
pushd %BuildStaging%\UnitTests
msbuild Tests.sln /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% > %test_output%
popd
call ReportBuildErrors.cmd %test_output%
if ERRORLEVEL 1 exit /B %ERRORLEVEL%

echo Running Unit Tests...
pushd %BuildStaging%\UnitTests
call RunTests.cmd
popd

