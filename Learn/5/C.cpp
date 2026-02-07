#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> diffs(n + 2, 0);

    for (long long i = 0; i < m; ++i) {
        long long l, r, d;
        cin >> l >> r >> d;
        diffs[l] += d;
        diffs[r + 1] -= d;
    }

    vector<long long> arr(n + 1, 0);
    for (long long i = 1; i <= n; ++i) {
        arr[i] = arr[i - 1] + diffs[i];
    }

    for (long long i = 1; i <= n; ++i) {
        cout << arr[i] << " ";
    }
}