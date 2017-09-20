@echo off

call MakeDevProjection.cmd >nul
call BuildCompiler.cmd %*
call BuildProjection.cmd %*
call RunCompileTests.cmd %*
call RunUnitTests.cmd %*
call BuildSamples.cmd %*