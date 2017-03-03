@echo off

echo Usage: PrereleaseProjection ^<response_file^> ^<output_folder^>

if "%1" == "" (
  echo.
  echo Invalid command format. No response file specified. See usage.
  goto :eof
)

if "%2" == "" (
  echo.
  echo Invalid command format. No output folder specified. See usage.
  goto :eof
)

..\..\FrontEnd\FrontEnd\bin\Release\cppwinrt1.exe @%1 -db Metadata.db
..\..\BackEnd\x86\Release\cppwinrt2.exe Metadata.db -out %2 -time
