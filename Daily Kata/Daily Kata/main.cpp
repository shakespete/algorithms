#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Node {
public:
    int val;
};

void swap(int a, int b, Node** arr) {
    Node* temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubble_sort(int N, Node** arr) {
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N - i; ++j)
            if (arr[j]->val > arr[j+1]->val)
                swap(j, j + 1, arr);
}

int main() {
    int num[] = { 4,2,7,9,1,6,3,5,8,0 };
    int N = sizeof(num) / sizeof(num)[0];
    
    Node** arr = new Node*[N];
    for (int i = 0; i < N; ++i) {
        Node* node = new Node;
        node->val = num[i];
        arr[i] = node;
    }
    
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);
    printf("\n");
    bubble_sort(N, arr);
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]->val);
    printf("\nFIN\n");
    
    return 0;
}

