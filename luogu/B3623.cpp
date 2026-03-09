#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> path;
    vector<bool> used(n + 1, false);

    auto dfs = [used, path, &k](int depth) {
        if (depth == k) {
            for (int i = 0; i < k; ++i) {
                cout << path[i] << " ";
            }
            cout << endl;
        }

        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(i);
            }
        }
    }
}