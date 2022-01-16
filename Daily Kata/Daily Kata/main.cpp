#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& vec) {
    int N = (int)vec.size();
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N - i; ++j)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    for (int i : arr) printf("%d ", i);
    printf("\n");
    
    bubbleSort(arr);
    for (int i : arr) printf("%d ", i);
    
    printf("\nFIN\n");
    
    return 0;
}
