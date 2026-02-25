#include <iostream>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
    lint n, m;
    cin >> n >> m;

    vector<lint> heights(n);

    lint maxHeight = 0;
    for (int i = 0; i < n; ++i) {
        lint h;
        cin >> h;

        heights[i] = h;
        maxHeight = max(maxHeight, h);
    }

    lint setMax = maxHeight, setMin = 0, result = 0;
    while (setMin <= setMax) {
        lint set = setMin + (setMax - setMin) / 2;

        lint total = 0;
        for (lint tree: heights) {
            total += max(0LL, tree - set);
            if (total >= m) {
                break;
            }
        }

        if (total >= m) {
            result = set;
            setMin = set + 1;
        } else {
            setMax = set - 1;
        }
    }

    cout << result << endl;
}