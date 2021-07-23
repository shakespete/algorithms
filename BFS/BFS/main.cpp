#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Simple Queue
class Queue {
    enum { DEF_CAP = 2 };
public:
    Queue(int cap = DEF_CAP);
    bool empty();
    void enq(int e);
    int deq();
private:
    int* q;
    int capacity;
    int front;
    int rear;
};

Queue::Queue(int cap) : front(0), rear(0), capacity(cap), q(new int[cap]) {};
bool Queue::empty() { return front == rear; }
void Queue::enq(int e) {
    if (rear == capacity) {
        int* temp = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) temp[i] = q[i];
        q = temp;
        capacity *= 2;
    }
    q[rear++] = e;
}
int Queue::deq() {
    if (!empty()) return q[front++];
    return -1;
}

// Graph (BFS)
class Graph {
public:
    Graph(int e);
    void addEdge(int v, int w);
    void BFS(int s);
private:
    int V;          // Number of vertices
    int** adjList;  // Adjacency list
    int* visited;
};

Graph::Graph(int e) {
    V = e;
    adjList = new int*[e];
    visited = new int[e];
    for (int i = 0; i < e; ++i)
        adjList[i] = new int[e]{0};
}
void Graph::addEdge(int v, int w) {
    adjList[v][w] = 1;
    adjList[w][v] = 1;
}
void Graph::BFS(int s) {
    Queue* q = new Queue();
    q->enq(s);
    
    while (!q->empty()) {
        int u = q->deq();
        visited[u] = 1;
        printf("%d ", u);
        for (int i = 0; i < V; ++i)
            if (adjList[u][i] == 1)
                if (visited[i] != 1) q->enq(i);
    }
}

int main() {
    Graph* g = new Graph(10);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 5);
    g->addEdge(3, 4);
    g->addEdge(4, 7);
    g->addEdge(5, 6);
    g->addEdge(6, 8);
    g->addEdge(6, 9);
    g->addEdge(2, 0);
    g->BFS(1);
//    g->BFS(7);
//    g->BFS(9);
    
    printf("\n");
    return 0;
}

/*
       1
    /  |  \
   2   3   5
   |   |   |
   0   4   6
       |  / \
       7 8   9
 
 */
