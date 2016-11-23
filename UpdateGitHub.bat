echo off
echo Usage: UpdateGitHub.bat ^<desired_version^> ^<GitHub_local_repo_root^>
echo.

set BUILD_NUMBER=%1
set LOCAL_GITHUB_PATH=%2

if "%BUILD_NUMBER%" neq "" (
  if "%LOCAL_GITHUB_PATH%" neq "" (
    if "%3" == "" (
        goto GoodFormat
    )
  )
)

echo Oops! Check your formatting.

:Errors
exit /b 1

:GoodFormat


set BUILD_ROOT=\\redmond\osg\Threshold\Tools\CORE\DEP\DART\CppForWinRT
set GITHUB_LAYOUT=x86\release\github_release

set FULL_GITHUB_LAYOUT_PATH=%BUILD_ROOT%\%BUILD_NUMBER%\%GITHUB_LAYOUT%

if not exist "%FULL_GITHUB_LAYOUT_PATH%" (
  echo Oops! Can't find the layout at %FULL_GITHUB_LAYOUT_PATH%
  goto :Errors
)

findstr /c:"# cppwinrt" %LOCAL_GITHUB_PATH%\README.md > NUL || (
  echo Oops! Expected a README.md file with first line contents "# cppwinrt". Check your destination folder.
  goto :Errors
)

for /d %%G in (%FULL_GITHUB_LAYOUT_PATH%\*) do (
  robocopy /MIR %FULL_GITHUB_LAYOUT_PATH%\%%~nxG %LOCAL_GITHUB_PATH%\%%~nxG

  if "%ERRORLEVEL%" neq "0" (
    echo Oops! robocopy exited with error code %ERRORLEVEL%
    goto :Errors
  )
)

echo.
echo SUCCESS! Layout has been mirrored. Got to %LOCAL_GITHUB_PATH% and run "git add *".
echo          Verify that the correct files are added, modified and deleted before checking in or pushing.

goto :eof