#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> freeClassrooms(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        int r;
        cin >> r;

        freeClassrooms[i] = r;
    }

    vector<ll> d(m+1, 0), s(m+1, 0), t(m+1, 0);

    for (int i = 1; i <= m; ++i) {
        cin >> d[i] >> s[i] >> t[i];
    }

    auto check = [&n, &s, &t, &d, &freeClassrooms](int k) -> bool {
        vector<ll> diff(n+2, 0);

        for (int i = 1; i <= k; ++i) {
            diff[s[i]] += d[i];
            diff[t[i]+1] -= d[i];
        }

        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += diff[i];
            if (sum > freeClassrooms[i]) {
                return false;
            }
        }

        return true;
    };

    int left = 1, right = m, ans = m + 1;

    if (check(m)) {
        cout << "0\n";
        return 0;
    }

    if (!check(1)) {
        cout << "-1\n1\n";
        return 0;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (ans == m + 1) {
        cout << "0" << endl;
    } else {
        cout << -1 << endl;
        cout << ans + 1 << endl;
    }

}