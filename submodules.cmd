@echo off
echo Initializing / updating submodules...
call git submodule init
call git submodule update
call git submodule foreach git pull
echo Done