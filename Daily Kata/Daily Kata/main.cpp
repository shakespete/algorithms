#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void insertionSort(vector<int>& A) {
    for (int j = 1; j < (int)A.size(); ++j) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }
}

void selectionSort(vector<int>& A) {
    for (int i = 0; i < (int)A.size() - 1; ++i) {
        int minPtr = i;
        for (int j = i + 1; j < (int)A.size(); ++j)
            if (A[j] < A[minPtr]) minPtr = j;
        swap(A[i], A[minPtr]);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    insertionSort(arr);
    for (int i : arr) printf("%d ", i);
    printf("\n");
    selectionSort(arr);
    for (int i : arr) printf("%d ", i);
    
    printf("\nFIN\n");
    
    return 0;
}
