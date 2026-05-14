#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n, k, sum;
        cin >> n >> k >> sum;

        priority_queue<int, vector<int>, greater<int>> pq;

        int curSum = 0, len = 0;
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;

            // cout << a << endl;

            curSum += a;
            len++;

            if (curSum == sum) {
                pq.push(len);
                // cout << len << endl;
                curSum = 0;
                len = 0;
            }
        }

        if ((int) pq.size() < k) {
            cout << -1 << endl;
        } else {
            int minSum = 0;

            for (int j = 0; j < k; ++j) {
                minSum += pq.top();
                pq.pop();
            }

            cout << minSum << endl;
        }
    }
}