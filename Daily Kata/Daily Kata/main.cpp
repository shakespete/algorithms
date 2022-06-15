#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int N = (int)arr.size();
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N - i; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void insertionSort(vector<int>& arr) {
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
    vector<int> arr{ 39, 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
//    1, 2, 3, 5, 7, 7, 8, 11, 17, 21, 39
    for (auto& i : arr) cout << i << " ";
    
    cout << "\n";
    insertionSort(arr);
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    printf("FIN\n");
    return 0;
}
