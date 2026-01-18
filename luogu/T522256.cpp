#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> sum(n + 1, 0);
    for (long long i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i];
    }

    vector<long long> result;

    bool tri = false;
    for (long long i = 0; i <= n - 3; ++i) {
        if (a[i] + a[i + 1] > a[i + 2]) {
            tri = true;
            break;
        }
    }
    if (tri) {
        result.push_back(3);
    }
    
    for (long long k = 4; k <= n; ++k) {
        
        long long total = sum[n] - sum[n - k];
        long long max = a[n - 1];
        long long other_sum = total - max;
        
        if (max < other_sum) {
            result.push_back(k);
        }
    }

    for (long long i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}