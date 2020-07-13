#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* A, int N) {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N - 1; ++j)
            if (A[j] > A[j+1]) swap(&A[j], &A[j+1]);
}

int main() {
    int arr[] = { 2,4,5,7,1,8,3,6 };
    int size = sizeof(arr) / sizeof(arr)[0];

    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    bubble_sort(arr, size);
    for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
