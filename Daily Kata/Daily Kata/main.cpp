#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int x, int y, int* A) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int partition(int start, int end, int* A) {
    int pivot = A[end];
    int x = start - 1;
    for (int i = start; i <= end; ++i)
        if (A[i] < pivot)
            swap(++x, i, A);
    swap(++x, end, A);
    return x;
}

void quick_sort(int start, int end, int* A) {
    if (start < end) {
        int p = partition(start, end, A);
        quick_sort(start, p - 1, A);
        quick_sort(p + 1, end, A);
    }
}

int main() {
    int num[] = { 4, 1, 8, 9, 0, 3, 6, 2, 7, 5 };
    int N = sizeof(num) / sizeof(num)[0];

    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    quick_sort(0, N - 1, num);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    printf("\nFIN\n");

    return 0;
}
