@echo off
setlocal EnableDelayedExpansion

SET /a FINALERRORLEVEL=0

FOR /r %%f IN ("*.exe") DO (
  echo executing %%f
  %%f
  IF NOT !ERRORLEVEL! == 0 (
    echo Test failure detected. Incrementing script's return value by 1.
    set /a FINALERRORLEVEL+=1
  )
)

echo ==============================================
echo DETECTED ^>^> !FINALERRORLEVEL! ^<^< TEST FAILURES
echo ==============================================

EXIT /b !FINALERRORLEVEL!