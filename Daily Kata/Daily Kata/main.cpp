#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void merge(int p, int q, int r, vector<int>& arr) {
    int i, j;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    
    for (i = 1; i <= n1; ++i) L[i] = arr[i + p - 1];
    for (j = 1; j <= n2; ++j) R[j] = arr[j + q];
    
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    
    i = j = 1;
    for (int k = p; k <= r; ++k) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        };
    }
}

void mergeSort(int p, int r, vector<int>& arr) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q, arr);
        mergeSort(q + 1, r, arr);
        merge(p, q, r, arr);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    mergeSort(0, (int)arr.size() - 1, arr);
    for (int i : arr) printf("%d ", i);
    printf("\nFIN\n");
    
    return 0;
}
