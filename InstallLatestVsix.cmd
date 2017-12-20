@echo off
setlocal ENABLEDELAYEDEXPANSION

call SetBuildVars.cmd %*

set share=\\redmond\osg\Threshold\Tools\CORE\DEP\DART\CppForWinRT
set done=0
for /f %%f in ('dir /b /O-D %share%') do call :install %%f 
goto :eof

:install
if "!done!"=="1" goto :eof
set done=1
echo Installing %1 C++/WinRT for %BuildConfiguration% %BuildPlatform%...
vsixinstaller.exe %share%\%1\%BuildPlatform%\%BuildConfiguration%\Microsoft.Windows.CppWinRT.vsix
exit /B