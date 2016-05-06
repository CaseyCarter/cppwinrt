@echo off

FrontEnd\FrontEnd\bin\Release\winmdc1.exe @Projections.NoXaml.txt
BackEnd\x86\Release\winmdc2.exe Projections\NoXaml\Metadata.db -out Projections\NoXaml -time

FrontEnd\FrontEnd\bin\Release\winmdc1.exe @Projections.Complete.txt
BackEnd\x86\Release\winmdc2.exe Projections\Complete\Metadata.db -out Projections\Complete -time
