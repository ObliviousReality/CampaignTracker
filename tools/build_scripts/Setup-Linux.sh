#!/bin/bash

pushd ../..
third-party/binaries/premake/linux/premake5 --cc=clang --file=Build.lua gmake2
popd
