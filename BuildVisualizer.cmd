@echo off

call MakeDevProjection.cmd >nul
call SetBuildVars.cmd %*

pushd cppwinrt

rem Clean target
rd %BuildPlatform%\%BuildConfiguration% /s /q >nul

echo Building compiler for %BuildConfiguration% %BuildPlatform%...
msbuild "visualizer.sln" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
set MsbuildErrorLevel=%ERRORLEVEL%

popd

exit /B %MsbuildErrorLevel%
