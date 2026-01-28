#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {}
};

class Queue {
    private:
        Node* frontPtr;
        Node* rearPtr;
        int cnt;

    public:
        Queue() : frontPtr(nullptr), rearPtr(nullptr), cnt(0) {}

        void push(int x) {
            if (rearPtr == nullptr) {
                rearPtr = new Node(x);
                frontPtr = rearPtr;
            } else {
                rearPtr->next = new Node(x);
                rearPtr = rearPtr->next;
            }
            cnt++;
        }

        void pop() {
            if (frontPtr != nullptr) {
                Node* temp = frontPtr;
                frontPtr = frontPtr->next;
                delete temp;
                cnt--;
                if (frontPtr == nullptr) {
                    rearPtr = nullptr;
                }
            } else {
                cout << "ERR_CANNOT_POP" << endl;
            }
        }

        void query() {
            if (frontPtr != nullptr) {
                cout << frontPtr->data << endl;
            } else {
                cout << "ERR_CANNOT_QUERY" << endl;
            }
        }

        void size() {
            cout << cnt << endl;
        }

};

int main() {
    int n;
    cin >> n;

    Queue queue;

    for (int i = 0; i < n; ++i) {
        int order;
        cin >> order;
        if (order == 1) {
            int value;
            cin >> value;

            queue.push(value);
        } else if (order == 2) {
            queue.pop();
        } else if (order == 3) {
            queue.query();
        } else if (order == 4) {
            queue.size();
        }
    }

}