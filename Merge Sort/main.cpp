#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int E;

class Node {
public:
	E val;
};

void merge(int start, int mid, int end, Node** arr, int N) {
	int i, j, k;
	int n1 = mid - start + 1;
	int n2 = end - mid;

	Node** L = new Node*[N];
	Node** R = new Node*[N];

	for (i = 0; i < n1; ++i) L[i] = arr[start + i];
	for (j = 0; j < n2; ++j) R[j] = arr[mid + j + 1];

	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2) {
		if (L[i]->val <= R[j]->val) {
			arr[k] = L[i];
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < n2) {
		arr[k] = R[j];
		++j;
		++k;
	}
}

void merge_sort(int start, int end, Node** arr, int N) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		merge_sort(start, mid, arr, N);
		merge_sort(mid + 1, end, arr, N);
		merge(start, mid, end, arr, N);
	}
}

int main() {
	int num[] = { 4, 7, 1, 6, 2, 0, 9, 8, 3, 5 };
	int N = sizeof(num) / sizeof(num)[0];
	Node** arr = new Node * [N];
	for (int i = 0; i < N; ++i) {
		Node* node = new Node();
		node->val = num[i];
		arr[i] = node;
	}

	for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);
	printf("\n");
	merge_sort(0, N - 1, arr, N);
	for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);
	printf("\n");
	return 0;
}