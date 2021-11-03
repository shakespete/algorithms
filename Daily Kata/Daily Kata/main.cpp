#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void maxHeapify(int i, vector<int> &array, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest;
    if (l < heapSize && array[l] > array[i]) largest = l;
    else largest = i;
    
    if (r < heapSize && array[r] > array[largest]) largest = r;
    
    if (largest != i) {
        swap(array[i], array[largest]);
        maxHeapify(largest, array, heapSize);
    }
}
void buildMaxHeap(vector<int> &array) {
    int heapSize = (int)array.size();
    int parentIdx = heapSize / 2 - 1;
    for (int i = parentIdx; i >= 0; --i) maxHeapify(i, array, heapSize);
}

void heapSort(vector<int> &array) {
    buildMaxHeap(array);
    int heapSize = (int)array.size();
    for (int i = heapSize - 1; i > 0; --i) {
        swap(array[0], array[i]);
        heapSize--;
        maxHeapify(0, array, heapSize);
    }
}

int main() {
    vector<int> arr = { 4, 1, 9, 10, 14, 8, 7, 3, 2, 16 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    heapSort(arr);
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    printf("FIN\n");

    return 0;
}
