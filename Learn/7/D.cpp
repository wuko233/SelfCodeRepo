#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> heights(n);

    vector<ll> dp(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;

        heights[i] = a;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[j] < heights[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result = max(result, dp[i]);
    }

    cout << result << endl;
}