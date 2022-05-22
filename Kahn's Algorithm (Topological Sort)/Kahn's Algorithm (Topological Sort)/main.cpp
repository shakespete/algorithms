//
//  main.cpp
//  Kahn's Algorithm (Topological Sort)
//
//  Created by Jose Mari Syjuco on 22/5/2022.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void topologySort(int N, vector<vector<int>>& deps) {
    vector<vector<int>> adjList(N);
    vector<int> depCount(N, 0);
    
    int M = (int)deps.size();
    for (int i = 0; i < M; ++i) {
        int x = deps[i][0];
        int y = deps[i][1];
        
        adjList[x].push_back(y);
        depCount[y]++; // Count number of x's dependent on y
    }
    
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (depCount[i] == 0) q.push(i); // If it's got no dependencies start with that
    }
    
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        
        cout << t << " ";
        for (auto i : adjList[t]) {
            depCount[i]--;
            if (depCount[i] == 0) q.push(i);
        }
    }
}

int main() {
    int N = 8;
    vector<vector<int>> depList = {
        {2, 0}, // x is a pre-requisite of y
        {7, 0},
        {7, 6},
        {4, 6},
        {4, 1},
        {0, 3},
        {0, 5},
        {0, 1},
        {6, 5}
    };
    
    topologySort(N, depList);
    
    cout << "\n";
    return 0;
}
