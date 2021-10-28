#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_N 100

void swap(int x, int y, vector<int> &A) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

void selectionSort(vector<int> &A) {
    int N = (int)A.size();
    
    for (int i = 0; i < N - 1; ++i) {
        int minPtr = i;
        for (int j = i + 1; j < N; ++j)
            if (A[j] < A[minPtr]) minPtr = j;
        
        swap(minPtr, i, A);
    }
}

int main() {
    vector<int> arr = { 8, 11, 5, 2, 9, 5, 6, 3 };
    auto N = arr.size();

    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    selectionSort(arr);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    printf("\nFIN\n");

    return 0;
}
