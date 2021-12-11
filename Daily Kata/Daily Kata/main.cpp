#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void maxHeapify(int i, vector<int>& vec, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest = i;
    if (l < heapSize && vec[l] > vec[largest]) largest = l;
    if (r < heapSize && vec[r] > vec[largest]) largest = r;
    
    if (largest != i) {
        swap(vec[i], vec[largest]);
        maxHeapify(largest, vec, heapSize);
    }
}

void buildMaxHeap(vector<int>& vec) {
    int heapSize = (int)vec.size();
    int parent = heapSize / 2 - 1;
    for (int i = parent; i >=0; --i)
        maxHeapify(i, vec, heapSize);
}

void heapSort(vector<int>& vec) {
    buildMaxHeap(vec);
    int heapSize = (int)vec.size();
    for (int i = heapSize - 1; i > 0; --i) {
        swap(vec[0], vec[i]);
        heapSize--;
        maxHeapify(0, vec, heapSize);
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
