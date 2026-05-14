#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n, k, x;
        cin >> n >> k >> x;

        vector<int> diff(n + 2, 0);

        for (int j = 0; j < k; ++j) {
            int l, r;
            cin >> l >> r;

            diff[l] += 1;
            if (r + 1 <= n + 1) {
                diff[r + 1] -= 1;
            }
        }

        int max = -1, idx = 0;

        vector<int> arr(n + 1, 0);

        int curr = 0;

        for (int j = 1; j <= n; ++j) {
            curr += diff[j];
            arr[j] = curr;

            // cout << arr[j] << " ";

            if (arr[j] >= x) {
                idx++;
                if (idx > max) {
                    max = idx;
                }
            } else {
                idx = 0;
            }
        }

        cout << max << endl;
    }
}