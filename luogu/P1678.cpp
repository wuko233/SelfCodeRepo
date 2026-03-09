#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> schools(m);

    for (int i = 0; i < m; ++i) {
        int l;
        cin >> l;

        schools[i] = l;
    }

    sort(schools.begin(), schools.end());

    long long unhappy = 0;

    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;

        auto it = lower_bound(schools.begin(), schools.end(), s);

        if (it == schools.end()) {
            unhappy += s - schools.back();
        } else if (it == schools.begin()) {
            unhappy += *it - s;
        } else {
            int diff1 = *it - s;
            int diff2 = s - *(it - 1);
            unhappy += min(diff1, diff2);
        }
    }

    cout << unhappy << endl;
}