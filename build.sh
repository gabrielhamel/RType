#!/bin/sh

# CMake exist ?
which cmake > /dev/null
cmake_exist=`echo $?`
if [ $cmake_exist = 1 ]; then
    echo "Cmake isn't not installed or isn't not in environment: https://cmake.org/download/"
    exit
fi

# Rebuild if build exist
if [ -d "build" ]; then
    rm -rf build
fi

mkdir build
cd build

cmake .. -G "Unix Makefiles"
cmake_worked=`echo $?`
if [ $cmake_worked = 1 ]; then
    exit
fi

make
cd ..
