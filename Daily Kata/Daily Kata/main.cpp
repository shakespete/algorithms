#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_N 100

void merge(int p, int q, int r, vector<int> &A) {
    int i, j, k;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];
    
    for (i = 1; i <= n1; ++i) L[i] = A[i + p - 1];
    for (j = 1; j <= n2; ++j) R[j] = A[j + q];
    
    L[n1 + 1] = MAX_N;
    R[n2 + 1] = MAX_N;
    
    i = j = 1;
    for (k = p; k <= r; ++k) {
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
}

void mergeSort(int p, int r, vector<int> &A) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q, A);
        mergeSort(q + 1, r, A);
        merge(p, q, r, A);
    }
}

int main() {
    vector<int> arr = { 8, 11, 5, 2, 9, 5, 6, 3 };
    auto N = arr.size();

    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    mergeSort(0, arr.size() - 1, arr);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    printf("\nFIN\n");

    return 0;
}
