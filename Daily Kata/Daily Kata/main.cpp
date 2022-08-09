#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class Queue {
    enum { DEF_CAP = 2 };
public:
    Queue(int cap = DEF_CAP);
    ~Queue();
    bool empty() const;
    void enq(int e);
    int deq();
private:
    int *q;
    int capacity;
    int front;
    int rear;
};

Queue::Queue(int cap) : front(0), rear(0), capacity(cap), q(new int[cap]) { }
Queue::~Queue() { while(!empty()) deq(); }
bool Queue::empty() const { return front == rear; }
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

class Graph {
public:
    Graph(int e);
    void addEdge(int v, int w);
    void BFS(int start);
private:
    int V;
    int** adjList;
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
void Graph::BFS(int start) {
    Queue* q = new Queue();
    q->enq(start);
    
    while (!q->empty()) {
        int u = q->deq();
        visited[u] = 1;
        cout << u << " ";
        for (int i = 0; i < V; ++i) {
            if (adjList[u][i] == 1) // If can reach i from u
                if (visited[i] != 1) q->enq(i); // if i has not been visited yet
        }
    }
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
    g->addEdge(1, 3);
    g->addEdge(1, 5);
    g->addEdge(3, 4);
    g->addEdge(4, 7);
    g->addEdge(5, 6);
    g->addEdge(6, 8);
    g->addEdge(6, 9);
    g->addEdge(2, 0);
    g->BFS(1);
    cout << "\nFIN\n";
    return 0;
}
