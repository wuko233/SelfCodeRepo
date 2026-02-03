#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        prefixSum[i + 1] = prefixSum[i] + a;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int result = prefixSum[r] - prefixSum[l - 1];
        cout << result << "\n";
    }
}