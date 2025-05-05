@echo off

pushd ..\..
third-party\binaries\premake\windows\premake5.exe --file=Build.lua vs2019
popd
pause
