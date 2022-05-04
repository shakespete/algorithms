#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

void heap_sort(vector<int>& arr) {
    buildMaxHeap(arr);
    int heapSize = (int)arr.size();
    for (int i = heapSize - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapSize--;
        maxHeapify(0, arr, heapSize);
    }
}

int main() {
    vector<int> arr{ 39, 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
//    1, 2, 3, 5, 7, 7, 8, 11, 17, 21, 39
    for (auto& i : arr) cout << i << " ";
    
    cout << "\n";
    heap_sort(arr);
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    printf("FIN\n");
    return 0;
}
