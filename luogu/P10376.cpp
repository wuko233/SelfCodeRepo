#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> dp(n + 2, 0);

    for (int i = 0; i <= c; ++i) {
        dp[i] = 1;
    }

    for (int x = c + 1; x <= n; ++x) {
        long long ways = 0;

        if (x - a > c) {
            ways += dp[x - a];
        } else {
            ways += 1;
        }

        if (x - b > c) {
            ways += dp[x - b];
        } else {
            ways += 1;
        }

        dp[x] = ways % 1000000007;
    }

    cout << dp[n] << endl;

}