#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    vector<int> degree(n + 1, 0);

    vector<vector<int>> connect(n + 1, vector<int>());

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;

        degree[u]++;
        degree[v]++;

        connect[u].push_back(v);
        connect[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; ++i) {
        sort(connect[i].begin(), connect[i].end());
    }

    for (int i = 1; i <= n; ++i) {
        cout << degree[i] << " ";

        for (int j = 0; j < connect[i].size(); ++j) {
            cout << connect[i][j] << " ";
        }

        cout << endl;
    }


}