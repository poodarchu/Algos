cmake_minimum_required(VERSION 3.8)
project(netease_game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp lazhu.cpp)
add_executable(netease_game ${SOURCE_FILES})