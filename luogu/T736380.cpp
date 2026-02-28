#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isFull(int x, int y, int z) {
    vector<int> sides = {x, y, z};

    sort(sides.begin(), sides.end());

    return sides[0] * sides[1] == sides[2] || sides[0] + sides[1] == sides[2];
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    int max = 0, cnt = 0;

    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;

        if (isFull(l, x, y)) {
            cnt++;
            max = max > l ? max : l;
        }
    }

    cout << cnt << " " << max << endl;

}