#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        ll a, b;
        cin >> a >> b;      

        ll g = gcd(a, b);

        vector<ll> gg;
        for (ll i = 2; i * i <= g; ++i) {
            if (g % i == 0) {
                gg.push_back(i);
            }
        }

        // ll count = 0;
        // ll result = -1;

        // for (ll j = g; j >= 1; --j) {
        //     if (a % j == 0 && b % j == 0) {
        //         count++;
        //         if (count == 3) {
        //             result = j;
        //             break;
        //         }
        //     }
        // }

        // cout << result << endl;
    }
}