#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> matches;

    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;

        matches.push_back({b, a});
    }

    sort(matches.begin(), matches.end());

    ll endTime = -1;
    ll cnt = 0;
    for (auto match: matches) {
        if (match.second >= endTime) {
            endTime = match.first;
            cnt++;
        }
    }

    cout << cnt << endl;

}