@echo off
del TestHeaders.output >nul 2>&1
rd TestHeaders /s /q >nul 2>&1
md TestHeaders
pushd TestHeaders
for /f %%i in ('dir /b ..\winrt\Windows*.h') do @call :Test %%~ni
popd
call :Timer
goto :eof

:Timer
for /f "tokens=5 delims= " %%i in ('echo.^|time^|findstr current') do @echo %%i
goto :eof

:Test
call :Timer
echo %1
echo #include ^"%1.h^" >%1.cpp
cl %1.cpp /c /nologo /I ..\winrt /EHsc /std:c++latest /d1permissive- >>..\TestHeaders.output
goto :eof