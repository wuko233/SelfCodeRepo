#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b){
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    unordered_map<string, int> values;

    for (int ord = 1; ord <= n; ++ord) {
        string order;
        cin >> order;

        if (order == "CAPTURE") {
            string codeName;
            int v;
            cin >> codeName >> v;

            values[codeName] += v;

        } else if (order == "REPORT") {
            int k;
            cin >> k;

            vector<pair<string, int>> blocks;
            for (const auto& block: values) {
                blocks.push_back(block);
            }

            sort(blocks.begin(), blocks.end(), compare);

            int cnt = min(k, (int) blocks.size());
            for (int i = 0; i < cnt; ++i) {
                cout << blocks[i].first << " " << blocks[i].second << endl;
            }
        }
    }
}