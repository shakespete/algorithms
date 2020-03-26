#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 31

void merge(int* A, int p, int q, int r) {
	int i, j, k;

	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];

	for (i = 1; i <= n1; ++i) L[i] = A[i + p - 1];
	for (j = 1; j <= n2; ++j) R[j] = A[j + q];

	L[n1 + 1] = MAX_N;
	R[n2 + 1] = MAX_N;

	i = 1;
	j = 1;
	for (k = p; k <= r; ++k) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
	}
}

void merge_sort(int* A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	int num[] = { 5,3,8,1,0,6,7,4,2 };
	int size = sizeof(num) / 4;

	for (int i = 0; i < size; ++i) printf("%d ", num[i]);
	printf("\n");
	merge_sort(num, 0, size - 1);
	for (int i = 0; i < size; ++i) printf("%d ", num[i]);
	printf("\n");
	return 0;
}