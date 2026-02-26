#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;

    vector<ll> candies(n);

    ll cnt = 0;

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;

        candies[i] = a;

        if (i == 0) continue;

        ll last = candies[i-1];
        if (last + a > x) {
            ll needDelete = last + a - x;
            if (a >= needDelete) {
                candies[i] -= needDelete;
            } else {
                candies[i] = 0;
                candies[i-1] -= needDelete - a;
            }

            cnt += needDelete;
        }

    }

    cout << cnt;
}