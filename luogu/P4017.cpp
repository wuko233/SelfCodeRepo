#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int mod = 80112002;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    vector<int> indegree(n + 1);
    vector<int> outdegree(n + 1);


    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);

        indegree[b]++;
        outdegree[a]++;
    }

    queue<int> q;

    vector<int> num(n + 1);

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            num[i] = 1;
        }
    }

    // 处理路径数量， 生产者（0入度）
    while (!q.empty()) {
        int head = q.front();
        q.pop();

        for (int v : graph[head]) {
            num[v] = (num[v] + num[head]) % mod;;

            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        if (outdegree[i] == 0) {
            ans = (ans + num[i]) % mod;
        }
    }

    cout << ans << endl;


}