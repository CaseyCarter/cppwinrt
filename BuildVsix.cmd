@echo off
setlocal

call SetBuildVars.cmd %*
call BuildVisualizer.cmd %*

pushd vsix

rem Clean targets
for /f %%i in ('dir /s /b %BuildConfiguration%') do @rd %%i /s /q >nul

echo Updating VSIX manifest version from cppwinrt\source\version.h
powershell -f UpdateVersion.ps1

echo Building Component VSIX for %BuildConfiguration% %BuildPlatform%...
msbuild vsix.csproj /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% /p:IsProductComponent=true
set MsbuildErrorLevel=%ERRORLEVEL%
if %MsbuildErrorLevel%==0 (
echo Building Standalone VSIX for %BuildConfiguration% %BuildPlatform%...
msbuild vsix.csproj /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform%  /p:IsProductComponent=false
set MsbuildErrorLevel=%ERRORLEVEL%
)

popd

exit /B %MsbuildErrorLevel%
