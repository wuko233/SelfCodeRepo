#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> seats(n);

    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        seats[i] = x;
    }

    sort(seats.begin(), seats.end());

    int left = 0, right = seats[n-1] - seats[0];

    auto check = [&k, &seats, &n](ll mid) {
        int cnt = 1;
        ll last = seats[0];

        for (int i = 1; i < n; ++i) {
            if (seats[i] - last >= mid) {
                cnt++;
                last = seats[i];
            }
        }

        return cnt >= k;
    };

    int ans = 0;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
}