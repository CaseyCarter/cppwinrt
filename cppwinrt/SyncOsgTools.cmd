@echo off
setlocal

if exist %~d0\osgtools (
echo ERROR: Must run this script from source repo
goto :eof
)

set cppwinrt=%~dp0
set synced=0
for %%i in (c d e f g r) do call :try_sync %%i
if %synced%==0 echo ERROR: Couldn't find or sync osgtools cppwinrt repo
endlocal && cd %cd%
exit /B %ERRORLEVEL%

:try_sync
if not %synced%==0 goto :eof
pushd %1:\OSGTools\src\Microsoft\Internal\Windows\Tools\CppWinRT >nul 2>&1
if not "%ERRORLEVEL%"=="0" goto :eof
del /s /q . >nul 2>&1
copy %cppwinrt% . >nul 2>&1
xcopy /d /i /j /r /s /y %cppwinrt%\source source >nul 2>&1
xcopy /d /i /j /r /s /y %cppwinrt%\strings strings >nul 2>&1
git add -u
git add .
git status
set synced=1
