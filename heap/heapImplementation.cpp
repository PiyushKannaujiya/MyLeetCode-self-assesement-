#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

public:

    // 🔹 Insert
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    // 🔹 Heapify Down
    void heapify(int i) {
        int n = heap.size();
        int smallest = i;

        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;

        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    // 🔹 Extract Min
    int extractMin() {
        if (heap.size() == 0) return -1;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
        return root;
    }

    // 🔹 Get Min
    int getMin() {
        if (heap.size() == 0) return -1;
        return heap[0];
    }

    // 🔹 Delete Index
    void deleteKey(int i) {
        if (i >= heap.size()) return;

        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // 🔹 Decrease Key
    void decreaseKey(int i, int newVal) {
        heap[i] = newVal;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    // 🔹 Print
    void print() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};
int main() {
    MinHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    h.print();          // 2 5 20 10

    cout << h.getMin() << endl;   // 2

    h.extractMin();
    h.print();          // 5 10 20

    h.deleteKey(1);
    h.print();

    return 0;
}