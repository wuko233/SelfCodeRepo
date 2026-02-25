#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> locs(n);

    ll maxLoc = 0;
    for (int i = 0; i < n; ++i) {
        ll loc;
        cin >> loc;

        locs[i] = loc;
        maxLoc = max(maxLoc, loc);
    }

    sort(locs.begin(), locs.end());

    ll left = 1;
    ll right = maxLoc - locs[0];
    ll result = 0;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        int count = 1;
        ll lastPlaced = locs[0];

        for (int i = 1; i < n; ++i) {
            if (locs[i] - lastPlaced >= mid) {
                count++;
                lastPlaced = locs[i];
                if (count >= m) {
                    break;
                }
            }
        }

        if (count >= m) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
}