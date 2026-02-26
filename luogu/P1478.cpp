#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    int a, b;
    cin >> a >> b;

    vector<pair<int, int>> apples;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        apples.push_back({y, x});
    }

    sort(apples.begin(), apples.end());

    int cnt = 0;
    for (auto apple: apples) {
        int height = apple.second;
        int needStrength = apple.first;

        if (a + b < height) continue;

        if (needStrength <= s) {
            cnt++;
            s -= needStrength;
        } else {
            break;
        }

    }

    cout << cnt << endl;
}