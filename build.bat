@echo off

:: CMake exist ?
where cmake.exe>NUL 2>NUL
if %ERRORLEVEL% neq 0 (
    echo Cmake isn't not installed or isn't not in environment: https://cmake.org/download/
    cmd /k
    exit 0
)

:: Remove if exist
if exist build (
    rd /S /Q build
)

mkdir build
cd build

cmake .. -DCMAKE_GENERATOR_PLATFORM=x64
cmake --build . --target ALL_BUILD --config Release

:: For the end
cd ..
cmd /k
exit 0
