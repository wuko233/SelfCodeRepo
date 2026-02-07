#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item {
    int time;
    long long profit;
};

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        int d, p;
        cin >> items[i].time >> items[i].profit;

    }

    sort(items.begin(), items.end(),
        [](Item a, Item b) {
            return a.time < b.time;
        }
    );

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for (auto& item : items) {
        if (minHeap.size() < item.time) {
            minHeap.push(item.profit);
        } else if (!minHeap.empty() && minHeap.top() < item.profit) {
            minHeap.pop();
            minHeap.push(item.profit);
        }
    }

    long long totalProfit = 0;
    while (!minHeap.empty()) {
        totalProfit += minHeap.top();
        minHeap.pop();
    }
    cout << totalProfit << endl;
    
}