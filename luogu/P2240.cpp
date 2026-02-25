#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    priority_queue<pair<double, int>> coinsRatio;

    for (int i = 0; i < n; ++i) {
        int m, v;
        cin >> m >> v;

        double ratio = (double) v / m;
        coinsRatio.push({ratio, m});
    }

    double totalValue = 0.0;
    int curWeight = 0;
    while (curWeight < t && !coinsRatio.empty()) {
        auto coinHeap = coinsRatio.top();

        double ratio = coinHeap.first;
        int weight = coinHeap.second;

        coinsRatio.pop();

        int availableWeight = t - curWeight;

        if (weight <= availableWeight) {
            totalValue += ratio * weight;
            curWeight += weight;
        } else {
            totalValue += ratio * availableWeight;
            curWeight += availableWeight;
        }
    }

    cout << fixed << setprecision(2) << totalValue << endl;
}