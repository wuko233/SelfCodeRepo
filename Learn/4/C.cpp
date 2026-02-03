#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long,vector<long long>, greater<long long>> rocksHeap;

    for (int i = 0; i < n; ++i) {
        long long w;
        cin >> w;
        rocksHeap.push(w);
    }

    long long power = 0;
    while (rocksHeap.size() != 1) {
        long long minWeight = rocksHeap.top();
        rocksHeap.pop();
        long long usedPower = rocksHeap.top() + minWeight;
        rocksHeap.push(usedPower);
        rocksHeap.pop();
        power += usedPower;
    }

    cout << power << endl;

}