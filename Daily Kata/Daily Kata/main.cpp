#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 1000

void merge(int* A, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    
    for (i = 1; i <= n1; ++i) L[i] = A[p+i-1];
    for (j = 1; j <= n2; ++j) R[j] = A[q+j];
    
    L[n1 + 1] = MAX_N;
    R[n2 + 1] = MAX_N;
    
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

void merge_sort(int* A, int p, int r) {
    if (p < r) {
        int q = (p+r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main() {
    int arr[] = { 2,4,5,7,1,0,3,6 };
    int size = sizeof(arr) / sizeof(arr)[0];
    
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    merge_sort(arr, 0, size - 1);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\nFIN\n");
    return 0;
}
