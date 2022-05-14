//
//  main.cpp
//  Counting Sort
//
//  Created by Jose Mari Syjuco on 14/5/2022.
//

#include <iostream>
#include <vector>

using namespace std;

// O(n + k) time | O(k) space where n is no of elements in a non-negative array whose maximum value is at most k
vector<int> countingSort(const vector<int>& array) {
    int maxValue = *max_element(array.begin(), array.end());
    
    vector<int> counts(maxValue + 1);
    for (int item : array) {
        ++counts[item];
    }

    int numItemsBefore = 0;
    for (auto it = counts.begin(); it != counts.end(); ++it) {
        int count = *it;
        *it = numItemsBefore;
        numItemsBefore += count;
    }

    vector<int> sorted(array.size());
    for (int item : array) {
        sorted[ counts[item] ] = item;
        counts[item] += 1;
    }

    return sorted;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = { 2312, 7632, 6542, 10, 87, 2321, 3221, 109234, 3223, 231, 2342, 321, 9, 1, 323, 421, 325, 65, 789, 4002 };
    for (auto& i : nums) cout << i << " ";
    
    cout << "\n";
    vector<int> ans = countingSort(nums);
    for (auto& i : ans) cout << i << " ";
    cout << "\n";
    
    printf("FIN\n");
    
    
    return 0;
}
