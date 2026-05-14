#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 998244353

void handler(vector<ll> control, vector<ll>& diff, vector<vector<ll>>& controls) {
    ll ctrl = control[0];
    ll l = control[1];
    ll r = control[2];

    if (ctrl == 1) {
        for (int i = l; i <= r; ++i) {
            diff[i] = (diff[i] + 1) % MOD;
        }

        controls.push_back(control);
    } else if (ctrl == 2) {
        for (auto control: controls) {
            handler(control, diff, controls);
        }
        controls.push_back(control);
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        ll n, m;
        cin >> n >> m;

        vector<ll> arr(n + 1, 0);
        vector<ll> diff(n + 1, 0);

        vector<vector<ll>> controls;

        for (int j = 0; j < m; ++j) {
            ll ctrl, l, r;
            cin >> ctrl >> l >> r;

            vector<ll> control = {ctrl, l, r};

            if (ctrl == 1) {
                for (int k = l; k <= r; ++k) {
                    diff[k] = (diff[k] + 1) % MOD;
                }
                controls.push_back(control);
            } else if (ctrl == 2) {
                for (auto control: controls) {
                    if (control[0] == 1) {
                        for (int k = control[1]; k <= control[2]; ++k) {
                            diff[k] = (diff[k] + 1) % MOD;
                        }
                    }
                }
                controls.push_back(control);
            }
        }

        for (int j = 1; j <= n; ++j) {
            arr[j] = (arr[j - 1] + diff[j]) % MOD;
        }

        for (int j = 1; j <= n; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

// int main() {
//     int T;
//     cin >> T;

//     for (int i = 0; i < T; ++i) {
//         ll n, m;
//         cin >> n >> m;

//         vector<ll> arr(n + 1, 0);
//         vector<ll> diff(n + 1, 0);

//         vector<vector<ll>> controls;

//         for (int j = 0; j < m; ++j) {
//             ll ctrl, l, r;
//             cin >> ctrl >> l >> r;

//             vector<ll> control = {ctrl, l, r};

//             handler(control, diff, controls);
//         }

//         for (int j = 1; j <= n; ++j) {
//             arr[j] = (arr[j - 1] + diff[j]) % MOD;
//         }

//         for (int j = 1; j <= n; ++j) {
//             cout << arr[j] << " ";
//         }
//         cout << endl;
//     }
// }




