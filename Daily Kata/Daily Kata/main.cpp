#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int j = 1; j < (int)arr.size(); ++j) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] < key) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int N = (int)arr.size();
    for (int i = 0; i < N - 1; ++i) {
        int minPtr = i;
        for (int j = i + 1; j < N; ++j)
            if (arr[j] < arr[minPtr])
                minPtr = j;
        
        swap(arr[i], arr[minPtr]);
    }
}

int main() {
    vector<int> arr{ 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
    for (auto& i : arr) cout << i << " ";
    
    cout << "\n";
    insertionSort(arr);
    for (auto& i : arr) cout << i << " ";
    
    cout << "\n";
    selectionSort(arr);
    for (auto& i : arr) cout << i << " ";
    
    printf("\nFIN\n");
    return 0;
}
