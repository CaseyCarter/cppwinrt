@echo off
echo Mock SDK inclusion of compiler and projection for test purposes (must run elevated)
mkdir "C:\Program Files (x86)\Windows Kits\10\Include\10.0.15063.0\cppwinrt" 2>nul
mklink /d /j "C:\Program Files (x86)\Windows Kits\10\Include\10.0.15063.0\cppwinrt\winrt" %~dp0\devprojection\winrt 2>nul
mklink "C:\Program Files (x86)\Windows Kits\10\bin\10.0.15063.0\x86\cppwinrt.exe" %~dp0\cppwinrt\x86\release\cppwinrt.exe 2>nul
echo.
echo In elevated editor, 
echo Add following to \Program Files (x86)\Windows Kits\10\DesignTime\CommonConfiguration\Neutral\UAP\10.0.15063.0\UAP.props:
echo   ^<CppWinRT_IncludePath Condition="'$(CppWinRT_IncludePath)' == ''"^>$(WindowsSdkDir)Include\10.0.15063.0\cppwinrt^</CppWinRT_IncludePath^>
echo   ^<WindowsSDK_IncludePath^>...$(WinRT_IncludePath);$(CppWinRT_IncludePath);...^</WindowsSDK_IncludePath^>
echo And add following to \Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\vsdevcmd\core\winsdk.bat:
echo   set "INCLUDE=...;%WindowsSdkDir%include\%WindowsSDKVersion%cppwinrt;%INCLUDE%"
echo.
echo Restart VS IDE and/or shell for changes to take effect

