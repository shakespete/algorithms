#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int E;

class Node {
public:
	E val;
};

void swap(int a, int b, Node** arr) {
	Node* temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int partition(int start, int end, Node** arr) {
	Node* pivot = arr[end];
	int x = start - 1;

	for (int i = start; i <= end; ++i)
		if (arr[i]->val < pivot->val)
			swap(i, ++x, arr);

	swap(++x, end, arr);
	return x;
}

void quick_sort(int start, int end, Node** arr) {
	if (start < end) {
		int p = partition(start, end, arr);
		quick_sort(start, p - 1, arr);
		quick_sort(p + 1, end, arr);
	}
}

int main() {
	int num[] = { 4, 1, 8, 9, 0, 3, 6, 2, 7, 5 };
	int N = sizeof(num) / sizeof(num)[0];

	Node** arr = new Node*[N];
	for (int i = 0; i < N; ++i) {
		Node* node = new Node;
		node->val = num[i];
		arr[i] = node;
	}

	for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);
	quick_sort(0, N - 1, arr);
	printf("\n");
	for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);

	return 0;
}