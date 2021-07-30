#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Graph (DFS)
class Graph {
public:
    Graph(int e);
    void addEdge(int v, int w);
    void DFS();
    void visit(int u);
private:
    int V;          // Number of vertices
    int** adjList;  // Adjacency list
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
    printf("%d ", u);
    for (int i = 1; i < V; ++i)
        if (adjList[u][i] == 1)
            if (visited[i] != 1)
                visit(i);
}

int main () {
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
    printf("\n");
    return 0;
}

/*
       1
    /  |  \
   2   5   9
   |   |
   3   6
   |  / \
   4  7 8
 
 */
