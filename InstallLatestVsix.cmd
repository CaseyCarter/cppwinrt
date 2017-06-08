@echo off

for /f %%f in ('dir /b /O-D \\redmond\osg\Threshold\Tools\CORE\DEP\DART\CppForWinRT') do call :install %%f && exit /B

:install
echo Installing %1...
vsixinstaller.exe /q \\redmond\osg\Threshold\Tools\CORE\DEP\DART\CppForWinRT\%1\x86\release\cppwinrt.vsix
exit /B