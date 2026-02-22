#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> arr;

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;

        arr.push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        ll b;
        cin >> b;

        auto it = lower_bound(arr.begin(), arr.end(), b);

        if (it != arr.end() && *it == b) {
            cout << (it - arr.begin()) + 1 << " ";
        } else {
            cout << -1 << " ";
        }
    }
}