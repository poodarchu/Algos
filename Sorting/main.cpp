#include <iostream>
#include "SelectSort.cpp"
#include "BubbleSort.cpp"
#include "InsertionSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "HeapSort.cpp"

using namespace std;

int main() {
    int arr[] = {34,35,53,6,432,1,43,754,85,25};
    int len = (int) sizeof(arr)/ sizeof(*arr);

    selection_sort(arr, len);

    for (int i = 0; i < 10; i++)
        cout << arr[i] << endl;


    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
    len = (int) sizeof(arrf) / sizeof(*arrf);

//    bubble_sort(arrf, len);
//    insertion_sort(arrf, len);
//    merge_sort_iterative(arrf, len);
//    merge_sort(arrf, len);
//    quick_sort_iterative(arrf, len);
//    quick_sort(arrf, len);
    heap_sort(arrf, len);

    for (int i = 0; i < len; i++)
        cout << arrf[i] << endl;

    return 0;
}