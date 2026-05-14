#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (y % x) {
        cout << 0 << endl;
        return 0;
    }

    int k = y / x;

    int d = 2, r = 0;
    while (d * d <= k) {
        if (k % d == 0) {
            r++;
            while (k % d == 0) {
                k /= d;
            }
        }
        d++;
    }

    if (k > 1) {
        r++;
    }

    cout << pow(2, r) << endl;
}