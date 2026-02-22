#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 998244353

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        arr[i] = a;
    }

    ll result = 1;

    for (int i = 0; i < n; ++i) {
        result *= (arr[i] + 1);
        result %= MOD;
    }

    result -= 1;

    cout << result % MOD << endl;
}