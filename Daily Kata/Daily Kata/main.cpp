#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int partition(int start, int end, vector<int>& vec) {
    int pivot = vec[end];
    int x = start - 1;
    for (int i = start; i <= end; ++i)
        if (vec[i] < pivot)
            swap(vec[++x], vec[i]);
    
    swap(vec[++x], vec[end]);
    return x;
}

void quickSelect(int start, int end, vector<int>& arr, int i) {
    int p = partition(start, end, arr);
    
    if (i == p) return;
    
    if (i > p) quickSelect(p + 1, end, arr, i);
    else quickSelect(start, p - 1, arr, i);
}

int kthLargest(vector<int>& arr, int k) {
    int N = (int)arr.size();
    // 1 2 3 4 5 n
    // 0 1 2 3 4 5
    int kthSmallest = N - k; // => refers to index of kth smallest
    
    quickSelect(0, N - 1, arr, kthSmallest);
    return arr[kthSmallest];
}

int main() {
    vector<int> arr{ 3, 7, 11, 2, 17, 7, 1, 5, 8 };
    
    int k = 3;
    int ans = kthLargest(arr, k);
    
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    cout << k << "rd Largest: " << ans << "\n";
    printf("\nFIN\n");
    return 0;
}
