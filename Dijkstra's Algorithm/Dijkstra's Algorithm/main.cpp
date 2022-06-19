//
//  main.cpp
//  Dijkstra's Algorithm
//
//  Created by Jose Mari Syjuco on 19/6/2022.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct pairCompare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
};

// Time: O((v + e) * log(v)) | Space: O(v)
// where v is # of vertices and e is # of edges
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int N = (int)edges.size();
    
    vector<int> minDistances(N, INT_MAX); // Vector to track shortest paths
    minDistances[start] = 0; // Update distance of starting vertex
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> minHeap;
    minHeap.push({start, 0}); // Insert starting point
    
    while (!minHeap.empty()) {
        auto [currVertex, currDistance] = minHeap.top();
        minHeap.pop();
        
        if (currDistance == INT_MAX) break; // Means there is no path to this vertex
        
        // Check all possible outbound edges of current vertex
        for (auto edge : edges[currVertex]) {
            int destination = edge[0];
            int distance = edge[1];
            
            int newPathDistance = currDistance + distance;
            int currPathDistance = minDistances[destination];
            
            // If new path distance is less than current path distance, update vector and min heap
            if (newPathDistance < currPathDistance) {
                minDistances[destination] = newPathDistance;
                minHeap.push({destination, newPathDistance});
            }
        }
    }
    
    vector<int> result;
    for (int i = 0; i < N; ++i) {
        if (minDistances[i] == INT_MAX) result.push_back(-1);
        else result.push_back(minDistances[i]);
    }
    return result;
}

int main() {
    int start = 0;
    vector<vector<vector<int>>> edges = {
        {{1, 7}},
        {{2, 6}, {3, 20}, {4, 3}},
        {{3, 14}},
        {{4, 2}},
        {},
        {},
    };
    
    vector<int> ans = dijkstrasAlgorithm(start, edges);
    for (int i = 0; i < (int)edges.size(); ++i) cout << ans[i] << " ";
    cout << "\nFIN\n";
    return 0;
}

//start: 0
//"edges": [
//  [[1, 7]],
//  [[2, 6], [3, 20], [4, 3]],
//  [[3, 14]],
//  [[4, 2]],
//  [],
//  [],
//]
//ans: [0, 7, 13, 27, 10, -1]
