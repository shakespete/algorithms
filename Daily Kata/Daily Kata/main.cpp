#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int partition(int start, int end, vector<int>& arr) {
    int pivot = arr[end];
    int x = start - 1;
    for (int i = start; i < end; ++i)
        if (arr[i] < pivot)
            swap(arr[++x], arr[i]);
    swap(arr[++x], arr[end]);
    return x;
}

void quickSort(int start, int end, vector<int>& arr) {
    if (start < end) {
        int p = partition(start, end, arr);
        quickSort(start, p - 1, arr);
        quickSort(p + 1, end, arr);
    }
}

int main() {
    vector<int> arr{ 39, 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
//    1, 2, 3, 5, 7, 7, 8, 11, 17, 21, 39
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    quickSort(0, (int)arr.size() - 1, arr);
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    printf("FIN\n");
    return 0;
}
