@echo off

echo #include "Precompiled.h"> Strings.cpp
echo.>> Strings.cpp
echo namespace Modern::Strings {>> Strings.cpp
echo.>> Strings.cpp
for %%i in (modern\*) do (
    <nul set/p=extern char const %%~ni[] = R^"(>>Strings.cpp
    type %%i>>Strings.cpp
    echo ^)^";>>Strings.cpp
    echo.>> Strings.cpp
)
echo }>> Strings.cpp

echo #pragma once> Strings.h
echo.>> Strings.h
echo namespace Modern::Strings {>> Strings.h
echo.>> Strings.h
for %%i in (modern\*) do (
    echo extern char const %%~ni[%%~zi];>>Strings.h
)
echo.>> Strings.h
echo }>> Strings.h