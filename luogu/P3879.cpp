#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, vector<int>> map;

    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;

        unordered_map<string, bool> visited;

        for (int j = 0; j < l; ++j) {
            string w;
            cin >> w;
            
            if (!visited[w]) {
                map[w].push_back(i + 1);
                visited[w] = true;
            }
            
        }
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        string w;
        cin >> w;

        if (map.count(w) == 0) {
            cout << endl;
        } else {
            for (int j : map[w]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

}