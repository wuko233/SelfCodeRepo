#include <iostream>

using namespace std;

int main() {
    int a, b, x, y, m;
    cin >> a >> b >> x >> y >> m;

    int cnt1 = 0, cnt2 = 0;

    if (x >= y) {
        swap(x, y);
        swap(a, b);
    }
    cnt1 = min(a, m / x);

    m -= cnt1 * x;

    cnt2 = min(b, m / y);

    cout << cnt1 + cnt2 << endl;
}