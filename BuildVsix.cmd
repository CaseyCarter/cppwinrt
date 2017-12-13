@echo off
setlocal

call SetBuildVars.cmd %*
call BuildVisualizer.cmd %*

pushd vsix

rem Clean targets
for /f %%i in ('dir /s /b %BuildConfiguration%') do @rd %%i /s /q >nul

echo Updating VSIX manifest version from cppwinrt\source\version.h
powershell -f UpdateVersion.ps1

echo Building VSIX for %BuildConfiguration% %BuildPlatform%...
msbuild vsix.csproj /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
set MsbuildErrorLevel=%ERRORLEVEL%

popd

exit /B %MsbuildErrorLevel%
