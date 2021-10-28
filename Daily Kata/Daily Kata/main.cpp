#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_N 100

void insertionSort(int N, vector<int> &A) {
    for (int j = 1; j < N; ++j) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            --i;
        }
        A[i + 1] = key;
    }
}

int main() {
    vector<int> arr = { 8, 11, 5, 2, 9, 5, 6, 3 };
    auto N = arr.size();

    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    insertionSort(N, arr);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    printf("\nFIN\n");

    return 0;
}
