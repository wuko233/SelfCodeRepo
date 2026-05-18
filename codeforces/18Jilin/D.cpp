#include <iostream>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        ll x, y;

        cin >> x >> y;

        ll z = -1;

        for (z = x + 1; z < y; z++) {
            if (gcd(z, x) == 1 && gcd(z, y) == 1) {
                break;
            }
        }
        cout << (z ? z != y : -1) << endl;
    }
}