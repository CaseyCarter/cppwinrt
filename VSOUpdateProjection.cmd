if /i not "%BuildPlatform%" == "x86" goto :eof
if /i not "%BuildConfiguration%" == "Release" goto :eof
set ScriptError=0
pushd Projection\winrt
git add *
if NOT "%ERRORLEVEL%"=="0" goto wrapup
git commit -m "Update for build %2"
if NOT "%ERRORLEVEL%"=="0" goto wrapup
REM Force push since no one else should be changing this repo
git -c http.extraheader="AUTHORIZATION: bearer %1" push -f origin

:wrapup
set GitError=%ERRORLEVEL%
popd
exit %GitError%