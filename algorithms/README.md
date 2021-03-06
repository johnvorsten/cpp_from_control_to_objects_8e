### How to use CMake

First, I'm using gcc and g++ compiles on a windows machine (Stupid..)
Anyway, this means I need to tell CMake to use GNU make instead of MS nmake
Use this command line option
```
>> cmake .. -G "MinGW Makefiles"
```

If I'm running cmake from a specific build directory then run
```
>> cd ./build
>> cmake .. -G "MinGW Makefiles"
```

## File structure
Now.. Make sure the file structure is as follows
```
C:.
├───build
├───include
│   ├───some-sub-directory
│   └───headerfile.hpp
└───src
│   ├───some-sub-directory
│   └───my-soruce-file.cpp
```

Place .cpp files under ./src
Place header files in ./include
Use ./build as the build folder

## CMakeLists.txt
```bash
cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Project name
project(assignment_merge_sort)


# Can manually add source files using set command
#set(SOURCES src/assignment-merge-sort.cpp src/other-file.cpp)  
# The GLOB file allows for wildcards
file(GLOB SOURCES "src/*.cpp")


# Executable
add_executable(assignment_merge_sort ${SOURCES})
#add_executable(${PROJECT_NAME} ${SOURCES}) # Alternative way to do it

# Bring in headers into the project
include_directories(include)
# Python headers
find_package(Python3 COMPONENTS Development)
target_include_directories(assignment_merge_sort PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(assignment_merge_sort Python3::Python)
```


## Using CMake with NMake and Visual Studio
~From https://www.40tude.fr/compile-cpp-code-with-vscode-cmake-nmake/
1. We will create a CMakeLists.txt file (I will later explain what it is)
2. We will write a first VS Code task which will call CMake in order to process the CMakeLists.txt file and generate a Makefile specific to a Debug version of our application.
3. We will write a VS Code task which will invoke NMake in order to process the generated Makefile. This is this task which will generate the executable in Debug (and Release) version.
4. We will tell VS Code how to debug our application when it is in Debug mode
5. We will write a last VS Code task which will call CMake in order to process the CMakeLists.txt file and generate a Makefile specific to a Release version of our application.

### Template for VSCode CMake command
This calls the command `>> cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..`

TODO - Change ${workspaceRoot}/build to ${currentWorkingDirectory}/../build to make it in build
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "CMake Debug",
            "type": "shell",
            "options": {
                "cwd": "${workspaceRoot}/build"
            },
            "command": "CMake",
            // Define CMAKE_BUILD_TYPE variable because makefiles generated by CMake are single-configuration.
            "args": ["-G 'MinGW Makefiles' -DCMAKE_BUILD_TYPE=Debug .."]
        }
     ]
}
```

### Template for VSCode NMake command

```json
{
    "label": "Make",
    "type": "shell",
    "options": {
        "cwd": "${workspaceRoot}/build"
    },
    "command": "nmake",
    "group": {
        "kind": "build",
        "isDefault": true
    }
}
```

# Compiler arguments example
I have libaries to include at C:\src\include
My file is located somewhere like C:/users/myself/VSCodeProjects/Project1/src/example.cpp
