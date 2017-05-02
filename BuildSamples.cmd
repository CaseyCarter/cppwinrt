@echo off
setlocal

call SetBuildVars.cmd %*

set test_output=%~dp0\BuildSamples.output
echo Building Samples...> %test_output%

pushd %BuildStaging%\Samples

rem Clean targets
for /f %%i in ('dir /s /b %BuildConfiguration%') do @rd %%i /s /q >nul

echo Building all samples for %BuildConfiguration% %BuildPlatform%...
for /f %%i in ('dir /s /b *.bat') do @echo %%i & pushd %%~pi & del *.obj,*.exe & call "%%i" 2>&1 >>%test_output% & popd 
for /f %%i in ('dir /s /b *.sln') do @echo %%i & msbuild "%%i" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% /p:AppxPackageSigningEnabled=false 2>&1 >>%test_output%

popd

call ReportBuildErrors.cmd %test_output%
exit /B %ERRORLEVEL%