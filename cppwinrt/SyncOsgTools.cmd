rem @echo off
setlocal

set cppwinrt=%~dp0
set synced=0
if %1.==. (
for %%i in (c d e f g h i j k l m n o p q r s t u v w x y z) do call :try_sync %%i:
) else (
call :try_sync %1
)
if %synced%==0 (
echo ERROR: Couldn't find or sync osgtools cppwinrt repo
echo Usage: %~n0 [^<repo root^>]
echo        where ^<repo root^> is the parent folder of the OSGTools repo
)
endlocal && cd %cd%
exit /B %ERRORLEVEL%

:try_sync
if not %synced%==0 goto :eof
pushd %1\OSGTools\src\Microsoft\Internal\Windows\Tools\CppWinRT >nul 2>&1
if not "%ERRORLEVEL%"=="0" goto :eof
del /s /q . >nul 2>&1
copy %cppwinrt% . >nul 2>&1
xcopy /d /i /j /r /s /y %cppwinrt%\source source >nul 2>&1
xcopy /d /i /j /r /s /y %cppwinrt%\strings strings >nul 2>&1
git add -u
git add .
git status
set synced=1
