@echo off

FrontEnd\FrontEnd\bin\Release\WinMDc1.exe @Projections.answers
BackEnd\x86\Release\Modern.exe Complete.db -out Projections\Complete
FrontEnd\FrontEnd\bin\Release\WinMDc1.exe @Projections.answers
BackEnd\x86\Release\Modern.exe Complete.db -out Projections\Minimal
FrontEnd\FrontEnd\bin\Release\WinMDc1.exe @Projections.answers
BackEnd\x86\Release\Modern.exe Complete.db -out Projections\NoXaml