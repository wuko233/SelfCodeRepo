#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& reverseGraph, vector<int>& ans, int start) {
    if (ans[node]) {
        return;
    }

    ans[node] = start;

    for (int neighbor : reverseGraph[node]) {
        dfs(neighbor, reverseGraph, ans, start);
    }


}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> reverseGraph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        reverseGraph[v].push_back(u);
    }

    vector<int> ans(n + 1, 0);

    for (int i = n; i >= 1; i--) {
        dfs(i, reverseGraph, ans, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

}