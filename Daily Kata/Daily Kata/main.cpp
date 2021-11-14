#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

// Time: O(n^2) Space: O(1)
void insertionSort(vector<int> &arr) {
    int N = (int)arr.size();
    for (int j = 1; j < N; ++j) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    insertionSort(arr);
    for (int i : arr) printf("%d ", i);
    printf("\n");
    printf("FIN\n");
    
    return 0;
}
