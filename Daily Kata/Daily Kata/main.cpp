#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> buildPattern(string substr) {
    vector<int> pattern(substr.size(), -1);
    int i = 1;
    int j = 0;
    
    while (i < substr.size()) {
        if (substr[i] == substr[j]) {
            pattern[i] = j;
            ++i;
            ++j;
        } else if (j > 0) {
            j = pattern[j - 1] + 1;
        } else {
            ++i;
        }
    }
    
    return pattern;
}

bool KMPAlgo(string str, string substr) {
    vector<int> pattern = buildPattern(substr);
    
    int N = (int)substr.size();
    int i = 0;
    int j = 0;
    
    while (i + N - j <= str.size()) {
        if (str[i] == substr[j]) {
            if (j == N - 1) return true;
            ++i;
            ++j;
        } else if (j > 0) {
            j = pattern[j - 1] + 1;
        } else {
            ++i;
        }
    }
    
    return false;
}

int main() {
    vector<int> arr{ 39, 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
//    1, 2, 3, 5, 7, 7, 8, 11, 17, 21, 39
//    for (auto& i : arr) cout << i << " ";
    
//    cout << "\n";
//    for (auto& i : arr) cout << i << " ";
    
    cout << KMPAlgo("abxabcabcaby", "abcaby") << "\n";
    cout << KMPAlgo("decadaafcdf", "daf") << "\n";
    printf("FIN\n");
    return 0;
}
