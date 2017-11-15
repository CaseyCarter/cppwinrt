@echo off
setlocal ENABLEDELAYEDEXPANSION

if "%1"=="stats" (
	set _compiler_stats = /Bt+ /d1templateStats 
	shift
)

set _namespace_spec=*.*.cpp
if "%1"=="spec" (
	set _namespace_spec=%2.cpp
	shift
	shift
) 

call SetBuildVars.cmd %*
set TestLocation=%BuildStaging%\CompileTests
set test_output=%~dp0\RunCompileTests.output
echo Executing Projection Compile Tests
echo Executing Projection Compile Tests...> %test_output%
pushd %TestLocation%

echo // RunCompileTests.cmd generated PCH > pch.h
echo #define WIN32_LEAN_AND_MEAN >> pch.h
echo #include "winrt\base.h" >> pch.h
echo #include "winrt\Windows.Foundation.h" >> pch.h
echo #include "winrt\Windows.Foundation.Collections.h" >> pch.h
echo.>> pch.h
echo using namespace winrt; >> pch.h
echo.>> pch.h
echo template^<typename T^> >> pch.h
echo T arg(); >> pch.h
echo.>> pch.h
echo #include "pch.h" > pch.cpp
del *.obj
call :Compile pch.cpp /Ycpch.h 

if %_namespace_spec%==*.*.cpp (
	powershell.exe "%~dp0\GenerateConstexprCompileTests.ps1" constexpr_test.cpp
	call :Compile constexpr_test.cpp
	rem x64 compiler required for consume/produce tests (else fatal error C1060: compiler is out of heap space)
	if "%BuildPlatform%" == "x64" (
		call :Compile consume.cpp
		call :Compile produce.cpp
	)
)

call :Compile %_namespace_spec% /Yupch.h 
call :Timer
popd
type %test_output%
goto :WrapUp

:Timer
for /f "tokens=5 delims= " %%i in ('echo.^|time^|findstr current') do @echo %%i
goto :eof

:Compile
call :Timer
echo %1
cl %* /c /MP /nologo /I .. /EHsc /std:c++latest /permissive- /await %_compiler_stats% >>%test_output%
goto :eof
rem todo: add clang

:WrapUp
call ReportBuildErrors.cmd %test_output%
exit /B %ERRORLEVEL%