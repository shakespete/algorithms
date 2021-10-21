#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 100

void merge(int p, int q, int r, int* A) {
    int i, j, k;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    
    for (i = 1; i <= n1; ++i) L[i] = A[i + p - 1];
    for (j = 1; j <= n2; ++j) R[j] = A[j + q];
    
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

void merge_sort(int p, int r, int* A) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q, A);
        merge_sort(q + 1, r, A);
        merge(p, q, r, A);
    }
}

int main() {
    int num[] = { 4, 1, 8, 9, 0, 3, 6, 2, 7, 5 };
    int N = sizeof(num) / sizeof(num)[0];

    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    merge_sort(0, N - 1, num);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    printf("\nFIN\n");

    return 0;
}
