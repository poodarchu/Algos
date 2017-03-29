//
// Created by Poodar Chu on 3/29/17.
//
#include <iostream>

using namespace std;

template<typename T>
void merge_sort_iterative(T arr[], const int len) {
    T* a = arr;
    T* b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T* temp = a; // 交换两个指针，将 a 指向本轮修改后的数组，b 指向下一轮待被填充的数组。
        a = b;
        b = temp;
    }
    if (a != arr) { // 如果 a 此时不是指向传入的原数组，那么 b 此时指向传入的原数组，反之亦然。
        for (int i = 0; i < len; i++)
            b[i] = a[i];     // a 保存的是修改后的数组，此时 a 中保存的是最后的结果，需要将最后结果保存到原数组的地址中。
        b = a;   // b 是动态创建的内存，需要将 b 重新指回原地址。
    }
    delete[] b;   // 释放 b
}



template<typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

template<typename T>
void merge_sort(T arr[], const int len) {
    T reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}
