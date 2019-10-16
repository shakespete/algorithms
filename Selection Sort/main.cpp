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

void selection_sort(int N, Node** arr) {
	for (int i = 0; i < N - 1; ++i) {
		int minPtr = i;
		for (int j = i + 1; j < N; ++j)
			if (arr[j]->val < arr[minPtr]->val) minPtr = j;
		swap(minPtr, i, arr);
	}
}

int main() {
	int num[] = {3, 1, 6, 8, 2, 4, 9, 0, 5, 7};
	int N = sizeof(num) / sizeof(num)[0];

	Node** arr = new Node*[N];
	for (int i = 0; i < N; ++i) {
		Node* node = new Node;
		node->val = num[i];
		arr[i] = node;
	}

	for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);
	selection_sort(N, arr);
	printf("\n");
	for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);

	return 0;
}