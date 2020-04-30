#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* A, int start, int end) {
	int pivot = A[end];
	int x = start - 1;
	for (int i = start; i <= end; ++i)
		if (A[i] < pivot)
			swap(&A[i], &A[++x]);

	swap(&A[++x], &A[end]);
	return x;
}

void quick_sort(int* A, int start, int end) {
	if (start < end) {
		int p = partition(A, start, end);
		quick_sort(A, start, p - 1);
		quick_sort(A, p + 1, end);
	}
}

int main() {
	int arr[] = { 2,4,5,7,1,0,8,3,6 };
	int size = sizeof(arr) / sizeof(arr)[0];

	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
	printf("\n");
	quick_sort(arr, 0, size - 1);
	for (int i = 0; i < size; ++i) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}