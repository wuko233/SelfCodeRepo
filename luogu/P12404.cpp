#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, t, x;
    cin >> n >> t >> x;

    long long maxCnt = min(2 * t * x, n);
    long long minCnt = x == 1 ? 2 : x;

    cout << maxCnt << " " << minCnt << endl;

}