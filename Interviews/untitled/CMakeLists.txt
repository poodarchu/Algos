cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_COMPILER /usr/local/bin/g++-7)
set(CMAKE_C_COMPILER /usr/local/bin/gcc-7)

set(SOURCE_FILES main.cpp cpp11_new_features.cpp cpp14_new_features.cpp test.cpp)
add_executable(untitled ${SOURCE_FILES})