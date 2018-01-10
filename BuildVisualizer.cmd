@echo off

call SetBuildVars.cmd %*

pushd cppwinrt

rem Clean target
rd %BuildConfiguration% /s /q >nul

echo Building visualizer for %BuildConfiguration% %BuildPlatform%...
msbuild "visualizer.sln" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
set MsbuildErrorLevel=%ERRORLEVEL%

popd

exit /B %MsbuildErrorLevel%
