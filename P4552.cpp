#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> diff(n);
    diff[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        diff[i] = arr[i] - arr[i-1];
    }

    long long pos = 0, neg = 0;
    for (int i = 1; i < n; ++i) {
        if (diff[i] > 0) pos += diff[i];
        else if (diff[i] < 0) neg += -diff[i];
    }

    cout << max(pos, neg) << endl;
    cout << abs(pos - neg) + 1 << endl;

    return 0;
}