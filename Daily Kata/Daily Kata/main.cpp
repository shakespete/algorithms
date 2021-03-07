#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int x, int y, int* A) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

void bubble_sort(int N, int* A) {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N - 1; ++j)
            if (A[j] > A[j + 1])
                swap(j, j + 1, A);
}

int main () {
    int num[] = {8, 3, 1, 6, 2, 4, 9, 0, 5, 7};
    int N = sizeof(num) / sizeof(num)[0];
    
    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    bubble_sort(N, num);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    printf("\nFIN\n");
    return 0;
}
