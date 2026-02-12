#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> position(n);

    for (int i = 0; i < n; ++i) {
        cin >> position[i];
    }

    ll totalVolume = 0;

    sort(position.begin(), position.end());

    vector<ll> prefixSum(n);

    for (int i = 0; i < n; ++i) {
        prefixSum[i] = position[i] + (i > 0 ? prefixSum[i - 1] : 0);
    }

    for (int i = 0; i < n; ++i) {
        totalVolume += i * position[i] - (i > 0 ? prefixSum[i - 1] : 0);
    }

    cout << totalVolume * 2 << endl;

    
}