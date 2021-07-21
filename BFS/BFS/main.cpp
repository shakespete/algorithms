#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Simple Queue
class Q {
    enum { DEF_CAP = 10 };
public:
    Q(int cap = DEF_CAP);
    bool empty();
    void enq(int e);
    int deq();
private:
    int* q;
    int capacity;
    int front;
    int rear;
};

Q::Q(int cap) : front(0), rear(0), capacity(cap), q(new int[cap]) {};
bool Q::empty() { return front == rear; }
void Q::enq(int e) {
    if (rear == capacity) {
        int* temp = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) temp[i] = q[i];
        q = temp;
        capacity *= 2;
    }
    q[rear] = e;
    rear++;
}
int Q::deq() {
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
    int V;
    int** adjList;
};


Graph::Graph(int e) {
    V = e;
    adjList = new int*[e];
    for (int i = 0; i < e; ++i) adjList[i] = new int[e]();
}
void Graph::addEdge(int v, int w) { adjList[v][w] = 1; }
void Graph::BFS(int s) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", adjList[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph* g = new Graph(10);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(3, 4);
    g->BFS(1);
    
    printf("\n");
    
    Q* q = new Q();
    q->enq(1);
    q->enq(2);
    q->enq(3);
    q->enq(4);
    q->enq(5);
    
    while (!q->empty()) {
        printf("%d ", q->deq());
    }
    printf("\n");
    
    return 0;
}
