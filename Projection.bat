@echo off

FrontEnd\FrontEnd\bin\Release\winmdc1.exe @Projection.UniversalSDK.txt
BackEnd\x86\Release\winmdc2.exe Metadata.db -out Projection -time
