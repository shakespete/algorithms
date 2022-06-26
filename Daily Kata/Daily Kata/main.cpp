#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

void merge(int p, int q, int r, vector<int>& arr) {
    int i, j;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];
    
    for (i = 1; i <= n1; ++i) L[i] = arr[p + i - 1];
    for (j = 1; j <= n2; ++j) R[j] = arr[q + j];
    
    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;
    
    i = j = 1;
    for (int k = p; k <= r; ++k  ) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
    }
}

void mergeSort(int p, int r, vector<int>& arr) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q, arr);
        mergeSort(q + 1, r, arr);
        merge(p, q, r, arr);
    }
}

int main() {
    vector<int> arr{ 39, 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
//    1, 2, 3, 5, 7, 7, 8, 11, 17, 21, 39
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    mergeSort(0, (int)arr.size() - 1, arr);
    for (auto& i : arr) cout << i << " ";
    cout << "\n";
    
    printf("FIN\n");
    return 0;
}
