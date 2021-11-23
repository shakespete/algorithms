#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void merge(int p, int q, int r, vector<int>& A) {
    int i, j, k;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    
    for (int i = 1; i <= n1; ++i) L[i] = A[i + p - 1];
    for (int j = 1; j <= n2; ++j) R[j] = A[j + q];
    
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    
    i = j = 1;
    for (k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
}

void mergeSort(int p, int r, vector<int>& A) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q, A);
        mergeSort(q + 1, r, A);
        merge(p, q, r, A);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    int N = (int)arr.size();
    mergeSort(0, N - 1, arr);
    for (int i : arr) printf("%d ", i);
    printf("\nFIN\n");
    
    return 0;
}
