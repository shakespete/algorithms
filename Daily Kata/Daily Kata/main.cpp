#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    int val;
};

void swap(int a, int b, Node** A) {
    Node* temp = A[a];
    A[a] = A[b];
    A[b] = temp;
};

int partition(int start, int end, Node** A) {
    Node* pivot = A[end];
    int x = start - 1;
    
    for (int i = start; i <= end; ++i) {
        if (A[i]->val < pivot->val)
            swap(i, ++x, A);
    }
    swap(end, ++x, A);
    return x;
}

void quick_sort(int start, int end, Node** A) {
    if (start < end) {
        int p = partition(start, end, A);
        quick_sort(start, p-1, A);
        quick_sort(p+1, end, A);
    }
}

int main() {
    int num[] = { 4, 1, 8, 9, 0, 3, 6, 1, 7, 5 };
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
    printf("\nFIN\n");

    return 0;
}
