@echo off

BackEnd\x86\Release\Modern.exe library -db -time -sdk "c:\Program Files (x86)\Windows Kits\10\Include\10.0.10586.0\winrt" -out Projections\NoXaml -noxaml
BackEnd\x86\Release\Modern.exe library -db -time -sdk "c:\Program Files (x86)\Windows Kits\10\Include\10.0.10586.0\winrt" -out Projections\Complete
BackEnd\x86\Release\Modern.exe library -db -time -sdk "c:\Program Files (x86)\Windows Kits\10\Include\10.0.10586.0\winrt" -out Projections\Minimal -include Windows.Foundation
