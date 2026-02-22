#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void dfs(int dep, int n, vector<int>& cur, vector<bool>& used) {
    if (dep == n) {
        for (int i = 0; i < n; ++i) {
            cout << setw(5) << cur[i];
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            cur[dep] = i;
            dfs(dep + 1, n, cur, used);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> cur(n);
    vector<bool> used(n + 1, false);

    dfs(0, n, cur, used);
}