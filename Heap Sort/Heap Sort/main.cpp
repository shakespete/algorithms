//
//  main.cpp
//  Heap Sort
//
//  Created by Jose Mari Syjuco on 2/11/21.
//

#include <stdio.h>
#include <vector>

using namespace std;

void maxHeapify(int i, vector<int> &vector, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest;
    if (l < heapSize && vector[l] > vector[i]) largest = l;
    else largest = i;
    
    if (r < heapSize && vector[r] > vector[largest]) largest = r;
    
    if (largest != i) {
        swap(vector[i], vector[largest]);
        maxHeapify(largest, vector, heapSize);
    }
}
vector<int> buildMaxHeap(vector<int> &vector) {
    int heapSize = (int)vector.size();
    int parentIdx = heapSize / 2 - 1;
    for (int i = parentIdx; i >= 0; --i) maxHeapify(i, vector, heapSize);
    return vector;
}

// O(nlog(n))
void heapSort(vector<int> &vector) {
    buildMaxHeap(vector);
    int heapSize = (int)vector.size();
    for (int i = heapSize - 1; i > 0; --i) {
        swap(vector[0], vector[i]);
        heapSize--;
        maxHeapify(0, vector, heapSize);
    }
}


int main() {
    vector<int> arr1 = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr1) printf("%d ", i);
    printf("\n");
    heapSort(arr1);
    for (int i : arr1) printf("%d ", i);
    printf("\n");
    
    printf("\n");
    vector<int> arr2 = {8, 5, 2, 9, 5, 6, 3};
    for (int i : arr2) printf("%d ", i);
    printf("\n");
    heapSort(arr2);
    for (int i : arr2) printf("%d ", i);
    printf("\nFIN\n");
    return 0;
}
