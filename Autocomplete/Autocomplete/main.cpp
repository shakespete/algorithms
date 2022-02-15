//
//  main.cpp
//  Autocomplete
//
//  Created by Jose Mari Syjuco on 15/2/2022.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    bool isWord = false;
    vector<Node *> children{vector<Node *>(26, NULL)};
};

class Trie {
public:
    Trie();
    void insert(string s);
    void dfs(Node* cursor, string prefix, vector<string>& suggestions);
    vector<string> autocomplete(string prefix);
private:
    Node* root;
};

Trie::Trie() { root = new Node(); }
void Trie::insert(string s) {
    Node* cursor = root;
    
    for (auto& c : s) {
        if (!cursor->children[c - 'a']) {
            cursor->children[c - 'a'] = new Node();
        }
        cursor = cursor->children[c - 'a'];
    }
    cursor->isWord = true;
}
void Trie::dfs(Node* cursor, string prefix, vector<string>& suggestions) {
    if (cursor->isWord) suggestions.push_back(prefix);
    
    for (char c = 'a'; c <= 'z'; ++c) {
        if (cursor->children[c - 'a']) {
            prefix += c;
            dfs(cursor->children[c - 'a'], prefix, suggestions);
            prefix.pop_back(); // Backtrack on this letter
        }
    }
}
vector<string> Trie::autocomplete(string prefix) {
    vector<string> suggestions;
    
    Node* cursor = root;
    for (auto& c : prefix) {
        if (!cursor->children[c - 'a']) return suggestions;
        cursor = cursor->children[c - 'a'];
    }
    
    dfs(cursor, prefix, suggestions);
    return suggestions;
}

int main(int argc, const char * argv[]) {
    Trie* trie = new Trie();
    
    vector<string> words = {"mobile","mouse","moneypot","monitor","mousepad"};
    for (auto& w : words) trie->insert(w);
    
    cout << "Search 'm': ";
    vector<string> results = trie->autocomplete("m");
    for (auto& res : results) cout << res << " ";
    cout << "\n";
    
    cout << "Search 'mon': ";
    vector<string> results1 = trie->autocomplete("mon");
    for (auto& res : results1) cout << res << " ";
    cout << "\n";
    
    cout << "Search 'mou': ";
    vector<string> results2 = trie->autocomplete("mou");
    for (auto& res : results2) cout << res << " ";
    cout << "\n";
    
    cout << "\nFIN\n";
    return 0;
}
