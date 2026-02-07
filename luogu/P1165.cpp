#include <iostream>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> boxes;
    multiset<int> weights;

    for (int i = 0; i < n; ++i) {
        int ord;
        cin >> ord;

        if (ord == 0) {
            int weight;
            cin >> weight;
            weights.insert(weight);
            boxes.push(weight);

        } else if (ord == 1) {
            if (!boxes.empty()) {
                int weight = boxes.top();
                auto it = weights.find(weight);
                weights.erase(it);
                boxes.pop();
            }
        } else if (ord == 2) {
            if (!weights.empty()) {
                cout << *weights.rbegin() << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}