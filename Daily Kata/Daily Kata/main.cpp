#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int e);
    void addEdge(int v, int w);
    void DFS();
    void visit(int u);
private:
    int V;
    int** adjList;
    int* visited;
};


Graph::Graph(int e) {
    V = e;
    adjList = new int*[e];
    visited = new int[e]{0};
    for (int i = 0; i < e; ++i)
        adjList[i] = new int[e]{0};
}
void Graph::addEdge(int v, int w) {
    adjList[v][w] = 1;
    adjList[w][v] = 1;
}
void Graph::DFS() {
    for (int i = 1; i < V; ++i)
        if (visited[i] != 1)
            visit(i);
            
}
void Graph::visit(int u) {
    visited[u] = 1;
    cout << u << " ";
    for (int i = 1; i < V; ++i)
        if (adjList[u][i] == 1)
            if (visited[i] != 1)
                visit(i);
}

int main() {
//    vector<int> arr{ 39, 3, 7, 11, 2, 17, 7, 1, 5, 21, 8 };
////    1, 2, 3, 5, 7, 7, 8, 11, 17, 21, 39
//    for (auto& i : arr) cout << i << " ";
//    cout << "\n";
//
//    mergeSort(0, (int)arr.size() - 1, arr);
//    for (auto& i : arr) cout << i << " ";
//    cout << "\n";
    Graph* g = new Graph(10);
    g->addEdge(1, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
    g->addEdge(1, 5);
    g->addEdge(5, 6);
    g->addEdge(6, 7);
    g->addEdge(6, 8);
    g->addEdge(1, 9);
    g->DFS();
    
    cout << "\nFIN\n";
    return 0;
}
