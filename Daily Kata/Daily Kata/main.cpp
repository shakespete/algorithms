#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr) {
    int N = (int)arr.size();
    for (int i = 0; i < N - 1; ++i) {
        int minPtr = i;
        for (int j = i + 1; j < N; ++j) {
            if (arr[j] < arr[minPtr]) minPtr = j;
        }
        swap(arr[minPtr], arr[i]);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    selectionSort(arr);
    for (int i : arr) printf("%d ", i);
    printf("\nFIN\n");
    
    return 0;
}
