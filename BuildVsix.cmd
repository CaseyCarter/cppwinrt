@echo off
setlocal

call SetBuildVars.cmd %*

pushd vsix

rem Clean targets
for /f %%i in ('dir /s /b %BuildConfiguration%') do @rd %%i /s /q >nul

set UpdateVersion=%4
if not "%UpdateVersion%"=="" (
echo Updating VSIX manifest version
powershell -f UpdateVersion.ps1
)

echo Building VSIX for %BuildConfiguration% %BuildPlatform%...
copy ..\%BuildStaging%\winrt\cppwinrt.natvis
msbuild vsix.csproj /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
set MsbuildErrorLevel=%ERRORLEVEL%

popd

exit /B %MsbuildErrorLevel%
