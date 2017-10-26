@echo off

call SetBuildVars.cmd %*

pushd cppwinrt

rem Clean target
rd %BuildPlatform%\%BuildConfiguration% /s /q >nul

echo Building compiler for %BuildConfiguration% %BuildPlatform%...
msbuild "cppwinrt.sln" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
set MsbuildErrorLevel=%ERRORLEVEL%

popd

exit /B %MsbuildErrorLevel%
