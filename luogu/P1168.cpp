#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> minHeap;
    priority_queue<ll> maxHeap;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (maxHeap.empty() || a > maxHeap.top()) {
            minHeap.push(a);
        } else {
            maxHeap.push(a);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if ((i + 1) % 2 != 0) {
            cout << maxHeap.top() << endl;
        }
    }
    
}