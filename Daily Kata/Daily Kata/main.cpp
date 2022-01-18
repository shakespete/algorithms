#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int partition(int start, int end, vector<int>& vec) {
    int pivot = vec[end];
    int x = start - 1;
    for (int i = start; i < end; ++i)
        if (vec[i] < pivot)
            swap(vec[++x], vec[i]);
    
    swap(vec[++x], vec[end]);
    return x;
}

void quickSort(int start, int end, vector<int>& vec) {
    if (start < end) {
        int p = partition(start, end, vec);
        quickSort(start, p - 1, vec);
        quickSort(p + 1, end, vec);
    }
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    quickSort(0, (int)arr.size() - 1, arr);
    for (int i : arr) printf("%d ", i);
    
    printf("\nFIN\n");
    
    return 0;
}
