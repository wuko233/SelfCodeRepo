#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> sts(n);

    for (int i = 0; i < n; ++i) {
        ll length;
        cin >> length;

        sts[i] = length;
    }

    sort(sts.begin(), sts.end());

    ll cnt = 0;

    for (int i = 0; i <= n - 3; ++i) {
        ll shortestSide = sts[i];

        int k = i + 2;

        for (int j = i + 1; j <= n - 2; ++j) {
            ll midSide = sts[j];
            while (k < n && shortestSide + midSide > sts[k]) {
                k++;
            }
            if (k > j) {
                cnt += k - j - 1;
            }
        }
    }

    cout << cnt << endl;
}