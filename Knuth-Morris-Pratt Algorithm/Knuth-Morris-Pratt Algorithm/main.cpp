//
//  main.cpp
//  Knuth-Morris-Pratt Algorithm
//
//  Created by Jose Mari Syjuco on 12/2/2022.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Time: O(m + n) | Space: O(n)
// where m is length of str and n is length of substr

// O(2n) => O(n)
vector<int> buildPattern(string substr) {
    vector<int> pattern(substr.size(), -1);
    int i = 1; // leading ptr
    int j = 0; // pattern finder
    
    while(i < substr.size()) {
        if (substr[i] == substr[j]) {
            pattern[i] = j; // Last time I saw this pattern ended at index j
            ++i;
            ++j;
        } else if (j > 0) {
            // Current doesn't match so check the previous char and
            // go to index where it last matched and start from there
            j = pattern[j - 1] + 1;
            // e.g. Go back to the last matching pattern + 1
        } else {
            // j is at 0 so no pattern so far, just increment i
            ++i;
        }
    }
    
    return pattern;
}

// O(2m) => O(m)
bool KMPAlgo(string str, string substr) {
    vector<int> pattern = buildPattern(substr);
    
    int N = (int)substr.size();
    int i = 0; // str cursor
    int j = 0; // substr cursor
    
    // Check that the substr is still within the bounds of the str
    while (i + N - j <= str.size()) {
        if (str[i] == substr[j]) {
            if (j == N - 1) return true; // We've reached the end of the substr
            ++i;
            ++j;
        } else if (j > 0) {
            // Go to the index where the pattern thus far was last found
            j = pattern[j - 1] + 1;
        } else {
            // j is at 0 so no pattern found so far
            ++i;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    cout << KMPAlgo("abxabcabcaby", "abcaby") << "\n";
    cout << KMPAlgo("decadaafcdf", "daf") << "\n";
    cout << "FIN\n";
    return 0;
}
