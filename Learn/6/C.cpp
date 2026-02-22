#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    int n, s;
    cin >> n >> s;

    priority_queue<ll, vector<ll>, greater<ll>> cost;

    ll total = 0;
    ll perweekCost = 0; // 每周的成本 i * s

    for (int i = 0; i < n; ++i) {
        ll c, y;
        cin >> c >> y;

        cost.push(c - perweekCost);

        for (int j = 0; j < y; j++) {
            if (cost.empty()) break;

            ll best = cost.top() + perweekCost; // 选择当前成本最低的方案，并加上成本
            total += best;
        }

        perweekCost += s; // 每周成本增加 s
    }

    cout << total << endl;
}