@echo off

call SetBuildVars %*

pushd cppwinrt
echo Building compiler for %BuildConfiguration% %BuildPlatform%...
msbuild "cppwinrt.sln" /nologo /m /p:Configuration=%BuildConfiguration% /p:Platform=%BuildPlatform% 
popd 
