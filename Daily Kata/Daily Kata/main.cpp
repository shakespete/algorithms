#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int j = 1; j < arr.size(); ++j) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] < key) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int minPtr = i;
        for (int j = i + 1; j < arr.size(); ++j)
            if (arr[j] < arr[minPtr]) minPtr = j;
        swap(arr[i], arr[minPtr]);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    selectionSort(arr);
    for (int i : arr) printf("%d ", i);
    printf("\n");
    insertionSort(arr);
    for (int i : arr) printf("%d ", i);
    
    printf("\nFIN\n");
    
    return 0;
}
