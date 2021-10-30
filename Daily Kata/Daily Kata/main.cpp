#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_N 100

void swap(int x, int y, vector<int> &A) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

int partition(int start, int end, vector<int> &arr) {
    int pivot = arr[end];
    int x = start - 1;
    for (int i = start; i <= end; ++i)
        if (arr[i] < pivot)
            swap(++x, i, arr);
    
    swap(++x, end, arr);
    return x;
}

void quickSort(int start, int end, vector<int> &arr) {
    if (start < end) {
        int p = partition(start, end, arr);
        quickSort(start, p - 1, arr);
        quickSort(p + 1, end, arr);
    }
}

int main() {
    vector<int> arr = { 8, 11, 5, 2, 9, 5, 6, 3 };
    auto N = arr.size();

    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    quickSort(0, arr.size() - 1, arr);
    printf("\n");
    for (int i = 0; i < N; ++i) printf("%d ", arr[i]);
    printf("\nFIN\n");

    return 0;
}
