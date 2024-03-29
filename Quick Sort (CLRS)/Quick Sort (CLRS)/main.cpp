//
//  main.cpp
//  Quick Sort (CLRS)
//
//  Created by Jose Mari Syjuco on 4/11/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int partition(int start, int end, vector<int> &arr) {
    int pivot = arr[end];
    int x = start - 1;
    for (int i = start; i < end; ++i)
        if (arr[i] < pivot)
            swap(arr[++x], arr[i]);
    
    swap(arr[++x], arr[end]);
    return x;
}

void quickSort(int start, int end, vector<int> &arr) {
    if (start < end) {
        int p = partition(start, end, arr);
        quickSort(start, p - 1, arr);
        quickSort(p + 1, end, arr);
    }
}

int main() {
    vector<int> arr = { 2, 8, 7, 9, 1, 3, 5, 6, 4 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    quickSort(0, (int)arr.size() -1, arr);
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    printf("FIN\n");
    return 0;
}
