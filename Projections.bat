@echo off

FrontEnd\FrontEnd\bin\Release\WinMDc1.exe @Projections.answers
BackEnd\x86\Release\WinMDc2.exe Complete.db -out Projections\Complete
FrontEnd\FrontEnd\bin\Release\WinMDc1.exe @Projections.answers
BackEnd\x86\Release\WinMDc2.exe Complete.db -out Projections\Minimal
FrontEnd\FrontEnd\bin\Release\WinMDc1.exe @Projections.answers
BackEnd\x86\Release\WinMDc2.exe Complete.db -out Projections\NoXaml