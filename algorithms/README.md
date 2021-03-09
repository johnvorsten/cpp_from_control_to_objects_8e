### How to use CMake

First, I'm using gcc and g++ compiles on a windows machine (Stupid..)
Anyway, this means I need to tell CMake to use GNU make instead of MS nmake
Use this command line option 
>> cmake .. -G "MinGW Makefiles"

If I'm running cmake from a specific build directory then run
>> cd ./build
>> cmake .. -G "MinGW Makefiles"

## File structure
Now.. Make sure the file structure is as follows
C:.
├───build
├───include
│   ├───some-sub-directory
│   └───headerfile.hpp
└───src
│   ├───some-sub-directory
│   └───my-soruce-file.cpp

Place .cpp files under ./src
Place header files in ./include
Use ./build as the build folder

## CMakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Project name
project(this_is_any_name_that_I_Want)

# Bring in headers into the project
include_directories(include)

# Can manually add source files using set command
#set(SOURCES src/assignment-merge-sort.cpp src/other-file.cpp)  
# The GLOB file allows for wildcards
file(GLOB SOURCES "src/*.cpp") # Only use this if I really want to include all .cpp files (There should only be one main() function)

# Executable
add_executable(assignment_algorithms ${SOURCES})
```