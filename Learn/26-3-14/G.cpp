#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);

    for (int i = 1; i <= n; ++i) {
        ll a;
        cin >> a;

        arr[i] = a;
    }

    for (int i = 0; i < q; ++i) {
        int ctl;
        cin >> ctl;

        if (ctl == 1) {
            ll v;
            cin >> v;

            for (int j = 1; j <= n; ++j) {
                arr[j] = min(arr[j], v);
            }

        } else {
            ll sum = 0;
            for (int j = 1; j <= n; ++j) {
                sum += arr[j];
            }
            cout << sum << endl;
        }
    }
}