#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    queue<int> q;
    vector<int> res;

    for (int i = 1; i <= n; ++i) {
        int a;
        while (cin >> a && a != 0) {
            graph[i].push_back(a);
            indegree[a]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        res.push_back(a);

        for (int v : graph[a]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

}