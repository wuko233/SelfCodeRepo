#include <iostream>

using namespace std;

int n, k;
int path[15];
int used[15];

void dfs(int step) {
    if (step == k) {
        for (int i = 0; i < k; i++) {
            cout << path[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = 1;
            path[step] = i;
            dfs(step + 1);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    dfs(0);
}