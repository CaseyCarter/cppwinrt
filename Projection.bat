@echo off

FrontEnd\FrontEnd\bin\Release\cppwinrt1.exe @Projection\SDKResponseFiles\UWP.10.0.15063.0.rsp -db Metadata.db
BackEnd\x86\Release\cppwinrt2.exe Metadata.db -out Projection -time
