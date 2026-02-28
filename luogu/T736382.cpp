#include <iostream>
#include <cmath>

using namespace std;

pair<int, int> compute(int x, int y, int z) {
    int c = 0;

    label:
    if ((x + y) % 2 != 0) {
        x -= y % x;
    } else {
        y -= x % y;
    }

    if (x < c) {
        x += floor(y / 2.0) + 1;
    }

    if (y < c) {
        y += floor(x / 2.0) + 1;
    }

    c++;
    if (c < z) {
        goto label;
    }

    return {x, y};
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int cnt = 0;

    for (int x1 = 10; x1 <= 99; x1++) {
        for (int y1 = 10; y1 <= 99; y1++) {
            if (compute(x1, y1, z) == make_pair(x, y)) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}