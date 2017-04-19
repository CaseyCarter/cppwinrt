@echo off
setlocal ENABLEDELAYEDEXPANSION

echo Executing projection tests... > TestClasses.output
pushd tests
if "%1"=="stats" (
	set _compiler_stats = /Bt+ /d1templateStats 
	shift
)
if not "%1"=="" (
	set _namespace_spec=%1.cpp
) else (
	set _namespace_spec=*.cpp
)
echo // TestClasses generated PCH > pch.h
echo #define WIN32_LEAN_AND_MEAN >> pch.h
echo #include "base.h" >> pch.h
echo #include "impl\complex_structs.h" >> pch.h
echo.>> pch.h
echo using namespace winrt; >> pch.h
echo.>> pch.h
echo template^<typename T^> >> pch.h
echo T arg(); >> pch.h
echo.>> pch.h
echo #include "pch.h" > pch.cpp
del *.obj
call :Compile pch.cpp /Ycpch.h 
for /f %%i in ('dir /b %_namespace_spec%') do call :Compile %%~ni.cpp /Yupch.h 
call :Timer
popd
type TestClasses.output
goto :eof

:Timer
for /f "tokens=5 delims= " %%i in ('echo.^|time^|findstr current') do @echo %%i
goto :eof

:Compile
call :Timer
echo %1
cl %* /c /nologo /I ..\winrt /EHsc /std:c++latest /permissive- /await %_compiler_stats% >>..\TestClasses.output
goto :eof
rem todo: add clang
