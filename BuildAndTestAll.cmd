@echo off

call BuildCompiler.cmd %*
call BuildProjection.cmd %*
call RunCompileTests.cmd %*
call RunUnitTests.cmd %*
call BuildSamples.cmd %*