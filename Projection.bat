@echo off

FrontEnd\FrontEnd\bin\Release\winmdc1.exe @Projection\SDKResponseFiles\UWP.10.0.14393.0.rsp -db Metadata.db
BackEnd\x86\Release\winmdc2.exe Metadata.db -out Projection -time
