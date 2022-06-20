#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int partition(int start, int end, vector<int>& arr) {
    int pivot = arr[end];
    int x = start - 1;
    for (int i = start; i <= end; ++i)
        if (arr[i] < pivot)
            swap(arr[++x], arr[i]);
    swap(arr[++x], arr[end]);
    return x;
}

void quickSelect(int start, int end, vector<int>& arr, int i) {
    int p = partition(start, end, arr);
    cout << "i: " << i << "\n";
    cout << "p: " << p << "\n";
    
    for (auto& e : arr) cout << e << " ";
    
    cout << "\n";
    
    if (i == p) return;
    
    if (i > p) quickSelect(p + 1, end, arr, i);
    else quickSelect(start, p - 1, arr, i);
}

int kthLargest(vector<int>& arr, int k) {
    int N = (int)arr.size();
    int kthSmallest = N - k;
    
    quickSelect(0, N - 1, arr, kthSmallest);
    return arr[kthSmallest];
}

int main() {
    vector<int> arr{ 39, 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
//    1, 2, 3, 5, 7, 7, 8, 11, 17, 21, 39
    for (auto& i : arr) cout << i << " ";
    
    cout << "\n";
    cout << kthLargest(arr, 3);
//    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    printf("FIN\n");
    return 0;
}
