#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
ll v[N];
bool isPrime[N];

ll qpow(ll a, ll n, ll p) {
    ll res = 1;
    ll cur = a;

    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * cur) % p;
        }

        cur = (cur * cur) % p;

        n /= 2;
    }

    return res;
}

void giveMePrimes() {
    for (int i = 2; i < N; i++) isPrime[i] = true;
    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int t, l, r;
    ll w, m;
    cin >> t >> w >> m;

    giveMePrimes();
    
    v[0] = 0;
    for (int i = 1; i < N; ++i) {
        if (isPrime[i]) {
            v[i] = (v[i-1] + qpow(i, w, m)) % m;
        } else {
            v[i] = v[i-1];
        }
    }
    
    while (t--) {
        cin >> l >> r;
        cout << (v[r] - v[l-1] + m) % m << '\n';
    }
    return 0;
}