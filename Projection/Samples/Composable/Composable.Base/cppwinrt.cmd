@echo off
echo ------ Running C++/WinRT compiler ------
setlocal
set compiler=..\..\..\..\cppwinrt\x86\release\cppwinrt.exe
if not exist %compiler% (
set compiler=..\..\..\..\cppwinrt\x86\debug\cppwinrt.exe
)
%compiler% %* -verbose
