#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

class Heap {
    enum { DEF_CAP = 100 };
public:
    Heap(int cap = DEF_CAP);
    ~Heap();
    int size() const;
    bool empty() const;
    int root() const;
    void push(int e);
    void pop();
private:
    int* H;
    int n;
    int capacity;
};

Heap::Heap(int cap) : H(new int[cap]), n(0), capacity(cap) { }
Heap::~Heap() { while (!empty()) pop(); }
int Heap::size() const { return n; }
bool Heap::empty() const { return n == 0; }
int Heap::root() const { return empty() ? INT_MIN : H[1]; }
void Heap::push(int e) {
    if (size() != capacity) {
        n++;
        H[n] = e;
        
        int current = n;
        while (current > 1 && H[current] < H[current / 2]) {
            int parent = current / 2;
            
            int temp = H[parent];
            H[parent] = H[current];
            H[current] = temp;
            current = parent;
        }
    }
}
void Heap::pop() {
    if (!empty()) {
        H[1] = H[n];
        --n;
        
        int current = 1;
        while (current * 2 <= n) {
            int child;
            int left = current * 2;
            int right = current * 2 + 1;
            
            if (left == n) child = left;
            else child = H[left] < H[right] ? left : right;
            
            if (H[current] < H[child]) break;
            
            int temp = H[child];
            H[child] = H[current];
            H[current] = temp;
            current = child;
        }
    }
}

int main() {
    vector<int> arr = { 8, 5, 11, 2, 9, 5, 6, 3 };
    auto N = arr.size();

    Heap* hp = new Heap();
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
        hp->push(arr[i]);
    }
    
    printf("\n");
    while (!hp->empty()) {
        printf("%d ", hp->root());
        hp->pop();
    }
    
    printf("\nFIN\n");

    return 0;
}
