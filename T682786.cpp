#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        
        intervals.push_back({l, r});

    }

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;
    for (const auto& interval : intervals) {
        if (merged.empty() || merged.back().second <= interval.first) {
            merged.push_back(interval);
        } else {
            merged.back().second = max(merged.back().second, interval.second);
        }
    }

    int length = 0;
    for (const auto& interval : merged) {
        length += interval.second - interval.first + 1;
    }
    if (length > m) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = merged.size();

    vector<int> space;
    for (int i = 0; i < cnt - 1; i++) {
        space.push_back(merged[i + 1].first - merged[i].second - 1);
    }
    sort(space.begin(), space.end());

    for (int s: space) {
        if (length + s <= m) {
            length += s;
            cnt--;
        } else {
            break;
        }
    }

    cout << cnt << endl;

}