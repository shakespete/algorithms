#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertion_sort(int* A, int N) {
	for (int j = 1; j < N; ++j) {
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] < key) {
			A[i + 1] = A[i];
			--i;
		}
		A[i + 1] = key;
	}
}

int main() {
	int arr[] = { 2,4,5,7,1,2,3,6 };
	int size = sizeof(arr) / sizeof(arr)[0];

	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
	printf("\n");
	insertion_sort(arr, size);
	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
	printf("\n");
	return 0;;
}