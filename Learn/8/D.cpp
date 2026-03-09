#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<int> c(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    dp[1] = {a[1], b[1], c[1]};

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    int ans = max(dp[n][0], max(dp[n][1], dp[n][2]));

    cout << ans << endl;
}