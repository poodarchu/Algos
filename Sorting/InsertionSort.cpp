//
// Created by Poodar Chu on 3/29/17.
//

#include <iostream>

using namespace std;

template <typename T>
void insertion_sort(T* arr, const int len) {
    int i, j;
    T temp;
    for (i = 0; i < len; i++)  {
        temp = arr[i];
        j = i-1;
        for (; j >= 0 && temp < arr[j]; j--)
            arr[j+1] = arr[j];
        arr[j+1] = temp;
    }
}
