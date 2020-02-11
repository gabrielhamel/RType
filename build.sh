#!/bin/sh

# CMake exist ?
which cmake > /dev/null
cmake_exist=`echo $?`
if [ $cmake_exist = 1 ]; then
    echo "Cmake isn't not installed or isn't not in environment: https://cmake.org/download/"
    exit
fi

# Conan exist ?
which conan > /dev/null
conan_exist=`echo $?`
if [ $conan_exist = 1 ]; then
    echo "Conan isn't installed or isn't in environment: https://conan.io/downloads.html"
    exit
fi

# Bincrafters is added ?
conan remote list | grep "bincrafters:" > /dev/null
bincrafters_added=`echo $?`
if [ $bincrafters_added = 1 ]; then
    conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
fi

# Rebuild if build exist
if [ -d "build" ]; then
    rm -rf build
fi

mkdir build
cd build

conan install .. --build=missing -s compiler.libcxx=libstdc++11
conan_worked=`echo $?`
if [ $conan_worked = 1 ]; then
    exit
fi

cmake .. -G "Unix Makefiles"
cmake_worked=`echo $?`
if [ $cmake_worked = 1 ]; then
    exit
fi

make
cd ..
