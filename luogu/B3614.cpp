#include <iostream>

using namespace std;

class Stack {
    private:
        unsigned long long* data;
        long long length;
        long long top;

    public:
        Stack(unsigned long long size) {
            data = new unsigned long long[size];
            length = size;
            top = -1;
        }

        ~Stack() {
            delete[] data;
        }

        void push(unsigned long long value) {
            if (top < length - 1) {
                data[++top] = value;
            }
        }

        void pop() {
            if (top >= 0) {
                --top;
            } else {
                cout << "Empty" << endl;
            }
        }

        void query() {
            if (top >= 0) {
                cout << data[top] << endl;
            } else {
                cout << "Anguei!" << endl;
            }
        }

        void size() {
            cout << top + 1 << endl;
        }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    for (long long j = 0; j < t; ++j) {
        

        long long n;
        cin >> n;

        Stack stack(n);

        for (long long i = 0; i < n; ++i) {
            string order;
            cin >> order;

            if (order == "push") {
                unsigned long long value;
                cin >> value;
                stack.push(value);
            } else if (order == "pop") {
                stack.pop();
            } else if (order == "query") {
                stack.query();
            } else if (order == "size") {
                stack.size();
            }
        }
    }

    
}