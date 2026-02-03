#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> mahoStones;

    for (int i = 0; i < n; ++i) {
        long long p;
        cin >> p;
        mahoStones.push_back(p);
    }

    sort(mahoStones.begin(), mahoStones.end());

    long long totalPower = 0;
    if (n == 3) {
        totalPower = mahoStones[0] * mahoStones[1] + mahoStones[1] * mahoStones[2] + mahoStones[0] * mahoStones[2];
    } else {
        totalPower += mahoStones[0] * mahoStones[1];
        totalPower += mahoStones[0] * mahoStones[2];

        for (int i = 1; i < n - 2; ++i) {
            totalPower += mahoStones[i] * mahoStones[i + 2];
        }

        totalPower += mahoStones[n - 2] * mahoStones[n - 1];

    }

    cout << totalPower % 998244353 << endl;
}