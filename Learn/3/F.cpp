#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        arr[i] = a;
    }

    vector<long long> PreSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        PreSum[i] = PreSum[i - 1] + arr[i - 1];
    }

    long long m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        long long l, r;
        cin >> l >> r;

        long long sum = PreSum[r] - PreSum[l - 1];
        cout << sum << endl;
    }
}