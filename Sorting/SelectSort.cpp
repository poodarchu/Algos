//
// Created by Poodar Chu on 3/29/17.
//

#include <iostream>

template<typename T>
void selection_sort(T* arr, const int len) {
    int i, j;
    int minIdx;
    for (i = 0; i < len-1; i++) {
        minIdx = i;
        for (j = i+1; j < len; j++)
            if (arr[minIdx] > arr[j])
                minIdx = j;
        std::swap(arr[i], arr[minIdx]);
    }
}