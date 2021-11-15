#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

// Time: O(n^2) | Space: O(1)
void selectionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int minPtr = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[minPtr]) minPtr = j;
        }
        swap(arr[i], arr[minPtr]);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    selectionSort(arr);
    for (int i : arr) printf("%d ", i);
    printf("\n");
    printf("FIN\n");
    
    return 0;
}
