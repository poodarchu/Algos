//
// Created by Poodar Chu on 3/29/17.
//

#include <iostream>

using namespace std;

template <typename T>
void bubble_sort(T* arr, const int len) {
    for (int i = 0; i < len-1; i++)
        for (int j = 0; j < len-1-i; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}
