cmake_minimum_required(VERSION 3.6)
project(Sorting)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SelectSort.cpp BubbleSort.cpp InsertionSort.cpp MergeSort.cpp QuickSort.cpp HeapSort.cpp)
add_executable(Sorting ${SOURCE_FILES})