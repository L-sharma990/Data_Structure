#include <iostream>
using namespace std;

class MaxHeap {
    int h[100];
    int sz;
public:
    MaxHeap() { sz = 0; }
    void push(int x) {
        h[sz] = x;
        int i = sz;
        sz++;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[p] < h[i]) {
                int t = h[p]; h[p] = h[i]; h[i] = t;
                i = p;
            } else break;
        }
    }
    bool empty() { return sz == 0; }
    int top() { return h[0]; }
    void pop() {
        if (sz == 0) return;
        h[0] = h[sz-1];
        sz--;
        int i = 0;
        while (1) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;
            if (l < sz && h[l] > h[largest]) largest = l;
            if (r < sz && h[r] > h[largest]) largest = r;
            if (largest != i) {
                int t = h[i]; h[i] = h[largest]; h[largest] = t;
                i = largest;
            } else break;
        }
    }
};

int main() {
    MaxHeap pq;
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(10);
    int x = pq.top();
    pq.pop();
}
