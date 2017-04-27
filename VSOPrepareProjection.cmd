echo Refreshing submodules...
pushd Projection\winrt
git checkout master
popd
git -c http.extraheader="AUTHORIZATION: bearer %1" submodule foreach git pull
if NOT "%ERRORLEVEL%"=="0" goto wrapup
echo Erasing headers in checked in projection module...
erase /s /q Projection\winrt\*.h

:wrapup
exit %ERRORLEVEL%