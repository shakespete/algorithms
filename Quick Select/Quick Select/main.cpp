//
//  main.cpp
//  Quick Select
//
//  Created by Jose Mari Syjuco on 23/1/22.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(int start, int end, vector<int>& arr) {
    int pivot = arr[end];
    int cursor = start - 1;
    for (int i = start; i < end; ++i)
        if (arr[i] < pivot)
            swap(arr[++cursor], arr[i]);
    
    swap(arr[++cursor], arr[end]);
    return cursor;
}

// Time: O(n) average, O(n^2) worst | Space: O(1)
void quickSelect(int start, int end, vector<int>& arr, int i) {
    int p = partition(start, end, arr);
    
    if (i == p) return; // Found k in the right place
    
    // K we're looking for is:
    if (i > p) quickSelect(p + 1, end, arr, i); // to the right of the partition
    else quickSelect(start, p - 1, arr, i);     // to the left of the partition
}

int kthLargest(vector<int>& arr, int k) {
    int N = (int)arr.size();
    int kthSmallest = N - k;
    
    quickSelect(0, N - 1, arr, kthSmallest);
    
    return arr[kthSmallest];
}

int main(int argc, const char * argv[]) {
    // 1, 2, 3, 5, 7, 7, 8, 11, 17
    vector<int> arr{ 3, 7, 11, 2, 17, 7, 1, 5, 8 };
    
    int k = 2;
    int ans = kthLargest(arr, k);
    
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    cout << k << "nd Largest: " << ans << "\n";
    return 0;
}
