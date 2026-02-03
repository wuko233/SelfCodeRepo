#include <iostream>
#include <vector>

using namespace std;

class Heap {
    private:
        vector<int> heap;

        int parent(int i) {
            return (i - 1) / 2;
        }

        int left(int i) {
            return (2 * i + 1);
        }

        int right(int i) {
            return (2 * i + 2);
        }

        void siftUp(int i) {
            while(i > 0 && heap[i] < heap[parent(i)]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void siftDown(int i) {
            int size = heap.size();
            int smallest = i;

            while(true) {
                int leftC = left(i);
                int rightC = right(i);

                if (leftC < size && heap[leftC] < heap[smallest]) {
                    smallest = leftC;
                }

                if (rightC < size && heap[rightC] < heap[smallest]) {
                    smallest = rightC;
                }

                if (smallest == i) break;

                swap(heap[i], heap[smallest]);
                i = smallest;
            }
        }

    public:
        void push(int value) {
            heap.push_back(value);
            siftUp(heap.size() - 1);
        }

        int top() {
            if (heap.empty()) throw runtime_error("Heap is empty");
            return heap[0];
        }

        void pop() {
            heap[0] = heap.back();
            heap.pop_back();
            if (!heap.empty()) {
                siftDown(0);
            }
        }



};

int main() {
    int n;
    cin >> n;

    Heap minHeap;
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int value;
            cin >> value;
            minHeap.push(value);
        } else if (op == 2) {
            cout << minHeap.top() << endl;
        } else if (op == 3) {
            minHeap.pop();
        }
    }

}
