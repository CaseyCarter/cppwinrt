@echo off

call SetBuildVars.cmd %*

pushd cppwinrt

rem Clean targets
for /f %%i in ('dir /s /b %BuildConfiguration%') do @rd %%i /s /q >nul

echo Building compiler for %BuildConfiguration% %BuildPlatform%...
msbuild "cppwinrt.sln" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
set MsbuildErrorLevel=%ERRORLEVEL%

popd

exit /B %MsbuildErrorLevel%
