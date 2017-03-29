//
// Created by Poodar Chu on 3/29/17.
//
#include <iostream>

using namespace std;

/**
 * Even a variable length array (VLA) is declared, the program compiles using g++ -std=c++0x.
 * VLA is not an official part of C++11 [1].
 * Clang supports such variable length arrays in very limited circumstances [2], that is :
 * - The element type of a variable length array must be a POD ("plain old data") type,
 *      which means that it cannot have any user-declared constructors or destructors, any base classes, or any members of non-POD type.
 *      All C types are POD types.
 * - Variable length arrays cannot be used as the type of a non-type template parameter.
 *  Hence, above code does not compile using clang, an Error of variable length array of non-POD element type will be given.
 *  For a variable length array, using STL vector is a good option.
 *  If you really want to use array, an alternative solution is mentioned in [3]: use a dynamically allocated array instead.
 *  In practice, as mentioned by Scott Meyers in “Effective STL”, vector and string are preferred to dynamically allocated arrays.
 */

struct Range {
    int start, end;
    Range(int s = 0, int e = 0) {start = s, end = e;}
};

template<typename T>
void quick_sort_iterative(T arr[], const int len) {
    if (len <= 0) return;

    //r[]模拟堆栈，p为数量，r[p++]为push，r[--p]为pop且取得元素
    Range *r = new Range[len]; int p = 0;
    r[p++] = Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if(range.start >= range.end) continue;
        T mid = arr[range.end];
        int left = range.start, right = range.end - 1;
        while (left < right) {
            while (arr[left] < mid && left < right) left++;
            while (arr[right] >= mid && left < right) right--;
            std::swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[range.end])
            std::swap(arr[left], arr[range.end]);
        else
            left++;
        r[p++] = Range(range.start, left - 1);
        r[p++] = Range(left + 1, range.end);
    }
    delete[] r;
    r = nullptr;  // clear to prevent using invalid memory reference (dangling pointer)
}


template<typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end) return;
    T mid = arr[end];  // select the last element as the pivot.
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right) left++;
        while (arr[right] >= mid && left < right) right--;
        std::swap(arr[left], arr[right]);
    }

    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

template<typename T>
void quick_sort(T arr[], const int len) {
    quick_sort_recursive(arr, 0, len - 1);
}