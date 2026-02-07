#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> freqs;

    for (long long i = 0; i < n; ++i) {
        long long a;
        cin >> a;

        freqs.push_back(a);
    }

    sort(freqs.begin(), freqs.end());

    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        
        auto it = lower_bound(freqs.begin(), freqs.end(), q);
        
        if (it != freqs.end()) {
            cout << *it << endl;
        } else {
            cout << "ERR_SIGNAL_LOST" << endl;
        }
    }


}