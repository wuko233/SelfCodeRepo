#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(m);
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    vector<long long> diff(n + 1, 0);

    for (int i = 1; i < m; ++i) {
        int a = p[i - 1];
        int b = p[i];
        if (a < b) {
            diff[a] += 1;
            diff[b] -= 1;
        } else {
            diff[b] += 1;
            diff[a] -= 1;
        }
    }

    vector<long long> cnt(n, 0);
    long long sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += diff[i];
        cnt[i] = sum;
    }

    vector<vector<int>> prices(n, vector<int>(3));
    for (int i = 1; i < n; ++i) {
        cin >> prices[i][0] >> prices[i][1] >> prices[i][2];
    }

    long long totalCost = 0;
    for (int i = 1; i < n; ++i) {
        if (cnt[i] == 0) continue;

        long long ticketCost = cnt[i] * prices[i][0];
        long long cardCost = cnt[i] * prices[i][1] + prices[i][2];
        totalCost += min(ticketCost, cardCost);
    }

    cout << totalCost << endl;

    return 0;
}