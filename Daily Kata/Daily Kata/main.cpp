#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertion_sort(int N, int* A) {
    for (int j = 1; j < N; ++j) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] < key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

int main() {
    int num[] = { 4, 1, 8, 9, 0, 3, 6, 2, 7, 5 };
    int N = sizeof(num) / sizeof(num)[0];

    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    insertion_sort(N, num);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", num[i]);
    printf("\nFIN\n");

    return 0;
}
