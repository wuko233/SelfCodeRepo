#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<string, string>> records;

    for (int i = 0; i < n; ++i) {
        string city, state;
        cin >> city >> state;
        records.emplace_back(city, state);
    }

    int cnt = 0;

    unordered_map<string, int> cityWithState;

    for (auto &record : records) {
        string key = record.second + record.first.substr(0, 2);
        cityWithState[key]++;
    }

    for (auto &record : records) {
        string cityPrefix = record.first.substr(0, 2);
        string state = record.second;

        if (cityPrefix != state) {
            string key = cityPrefix + state;
            if (cityWithState.find(key) != cityWithState.end()) {
                cnt += cityWithState[key];
            }
        }
    }

    cout << cnt / 2 << "\n";
}