
echo Initializing / updating submodules...
call git submodule init
call git submodule update

REM Make sure default branches are checked out
pushd Projection\winrt
call git checkout master
popd

call git submodule foreach git pull
echo Done