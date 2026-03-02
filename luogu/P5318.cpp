#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct Article {
    int id;
    // vector<int> references;
    set<int> references;
};

void dfs(int id, vector<Article>& articles, vector<bool>& visited) {
    cout << id << " ";
    
    visited[id] = true;

    for (int ref : articles[id].references) {
        if (!visited[ref]) {
            dfs(ref, articles, visited);
        }
    }
}

void bfs(int id, vector<Article>& articles, vector<bool>& visited) {
    queue<int> q;

    visited[id] = true;
    q.push(id);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for (int ref : articles[cur].references) {
            if (!visited[ref]) {
                visited[ref] = true;
                q.push(ref);
            }
        }
    }

    
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<Article> articles(n + 1);

    for (int i = 1; i <= n; ++i) {
        articles[i].id = i;
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;

        articles[x].references.insert(y);
    }

    vector<bool> visited(n + 1, false);

    dfs(1, articles, visited);

    cout << endl;

    fill(visited.begin(), visited.end(), false);

    bfs(1, articles, visited);

    cout << endl;
}