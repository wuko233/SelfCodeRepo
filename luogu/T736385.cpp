#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> arr(n, vector<int>(m));

    unordered_set<int> colors;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            arr[i][j] = a;

            colors.insert(a);
        }
    }

    if (colors.size() < d) {
        cout << "Hrk" << endl;
        return 0;
    }

    int maxArea = 0;

    for (int top = 0; top <n; ++top) {

        vector<unordered_map<int, int>> colorCount(m);
        
        for (int btm = top; btm < n; ++btm) {

            for (int col = 0; col < m; ++col) {
                int color = arr[btm][col];
                colorCount[col][color]++;
            }

            int left = 0;
            unordered_map<int, int> windowColorCount;
            int maxWidth = 0;


            for (int right = 0; right < m; ++right) {
                for (auto &entry : colorCount[right]) {
                    windowColorCount[entry.first] += entry.second;
                }

                while (windowColorCount.size() > d && left <= right) {
                    for (auto &entry : colorCount[left]) {
                        windowColorCount[entry.first] -= entry.second;
                        if (windowColorCount[entry.first] <= 0) {
                            windowColorCount.erase(entry.first);
                        }
                    }
                    left++;
                }

                if (windowColorCount.size() == d) {
                    maxWidth = max(maxWidth, right - left + 1);
                }
            }

            int height = btm - top + 1;
            maxArea = max(maxArea, height * maxWidth);

        }
    }

    cout << maxArea << endl;

}