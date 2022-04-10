//
//  main.cpp
//  Cache (LRU)
//
//  Created by Jose Mari Syjuco on 10/4/2022.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int val;
    Node(int k, int v) {
        key = k;
        val = v;
    }
};

class LRUCache {
public:
    list<Node*> recentList;
    unordered_map<int, list<Node*>::iterator> cache;
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
private:
    int maxSize;
};


LRUCache::LRUCache(int capacity) : maxSize(capacity) { }
int LRUCache::get(int key) {
    // Key is not in cache
    if (cache.find(key) == cache.end()) return INT_MIN;
    
    // Get iterator and reposition (splice) node in the doubly linked list
    auto iterRef = cache.find(key);
    recentList.splice(recentList.begin(), recentList, iterRef->second);
    
    // Get node and return value
    Node* node = *iterRef->second;
    return node->val;
}
void LRUCache::put(int key, int value) {
    // If key does not exist in cache, check if max cap reached
    if (cache.find(key) == cache.end()) {
        // Remove least recently used from back of list
        if (cache.size() == maxSize) {
            Node* nodeToDelete = recentList.back();
            recentList.pop_back();
            
            // Delete key from cache
            cache.erase(nodeToDelete->key);
        }
        
        // Add new node to ll and update cache
        Node* node = new Node(key, value);
        recentList.push_front(node);
        auto iterRef = recentList.begin();
        cache.insert({ key, iterRef });
    } else {
        // key already in cache
        auto iterRef = cache.find(key);
        // Reposition node to front of list
        recentList.splice(recentList.begin(), recentList, iterRef->second);
        // Update node value
        Node* node = *iterRef->second;
        node->val = value;
    }
}

int main(int argc, const char * argv[]) {
    LRUCache* cache = new LRUCache(2);
    
    cache->put(1, 1); // cache: {1=1}
    cache->put(2, 2); // cache: {1=1, 2=2}
    cout << cache->get(1) << "\n";    // return 1
    cache->put(3, 3); // evicts key 2 => cache: {1=1, 3=3}
    cout << cache->get(2) << "\n";    // returns MIN (not found)
    cache->put(4, 4); // evicts key 1 => cache is {4=4, 3=3}
    cout << cache->get(1) << "\n";    // return MIN (not found)
    cout << cache->get(3) << "\n";    // return 3
    cout << cache->get(4) << "\n";    // return 4
    return 0;
}
