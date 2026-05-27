#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<ll> b(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    for (ll target: a) {
        if (binary_search(b.begin(), b.end(), target)) {
            cout << target << " ";
        }
    }

    cout << endl;
}