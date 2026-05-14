#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        ll t, n, m;
        cin >> t >> n >> m;

        // 标记机子占用时间
        vector<ll> machine(t + 1, 0);

        // 标记队友想吃时间
        vector<ll> eat(t + 1, 0);

        // 仅当机子占用且队友想吃时，才会吃掉

        for (int j = 0; j < m; ++j) {
            ll id, l, r;
            cin >> id >> l >> r;

            if (id == 0) {
                for (ll k = l; k <= r; ++k) {
                    machine[k]++;
                }
            } else {
                for (ll k = l; k <= r; ++k) {
                    eat[k]++;
                }
            }
        }

        ll ate = 0;

        for (ll j = 1; j <= t; ++j) {
            if (machine[j] > 0 && eat[j] > 0) {
                ate += eat[j];
            }
        }
        
        cout << ate << endl;

    // for (ll i = 0; i < T; ++i) {
    //     ll t, n, m;
    //     cin >> t >> n >> m;

    //     vector<ll> diff(t + 1, 0);

    //     vector<ll> eat(t + 1, 0);

    //     for (ll j = 0; j < m; ++j) {
    //         ll id, l, r;
    //         cin >> id >> l >> r;

    //         if (id == 0) {
    //             diff[l]++;
    //             if (r + 1 <= t) {
    //                 diff[r + 1]--;
    //             }
    //         } else {
    //             eat[l]++;
    //             if (r + 1 <= t) {
    //                 eat[r + 1]--;
    //             }
    //         }
    //     }

    //     ll cur = 0, human = 0, ate = 0;
    //     for (ll j = 1; j <= t; ++j) {
    //         cur += diff[j];
    //         human += eat[j];

    //         if (cur > 0) {
    //             ate += human;
    //         }
    //     }

    //     cout << ate << endl;
    }
}