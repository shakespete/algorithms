#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void maxHeapify(int i, vector<int>& arr, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest = i;
    if (l < heapSize && arr[l] > arr[largest]) largest = l;
    if (r < heapSize && arr[r] > arr[largest]) largest = r;
    
    if (largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(largest, arr, heapSize);
    }
}

void buildMaxHeap(vector<int>& arr) {
    int heapSize = (int)arr.size();
    int parent = heapSize / 2 - 1;
    for (int i = parent; i >= 0; --i)
        maxHeapify(i, arr, heapSize);
}

void heapSort(vector<int>& arr) {
    buildMaxHeap(arr);
    int heapSize = (int)arr.size();
    
    for (int i = heapSize - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapSize--;
        maxHeapify(0, arr, heapSize);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    heapSort(arr);
    for (int i : arr) printf("%d ", i);
    
    printf("\nFIN\n");
    
    return 0;
}
