#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        for (int i = 1; i < m; ++i) {
            int front = q.front();
            q.push(front);
            q.pop();
        }
        cout << q.front() << " ";
        q.pop();
    }

}