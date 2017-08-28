@echo off
echo ------ Running C++/WinRT compiler ------
setlocal
set compiler=..\..\..\cppwinrt\x86\release\cppwinrt.exe
if not exist %compiler% (
set compiler=..\..\..\cppwinrt\x86\debug\cppwinrt.exe
)
%compiler% -in packages\Win2D.uwp.1.21.0\lib\uap10.0\Microsoft.Graphics.Canvas.winmd -ref 10.0.15063.0 -verbose -out Win2D
