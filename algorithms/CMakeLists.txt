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
target_link_libraries(assignment_merge_sort Python3::Python ${Python_LIBRARY_DIRS})