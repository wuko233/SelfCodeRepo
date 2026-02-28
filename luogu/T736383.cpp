#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> isExist(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;

            isExist[i][j] = x;
        }
    }

    int cnt = 0;

    int x = 0, y = 0, curD = 0, isRerverse = 0;

    while (curD < n * m) {

        for (int i = 0; i < d && curD < n * m; ++i) {
            if (isExist[x][y]) {
                cnt++;
            }

            if (!isRerverse) {
                y++;

                if (y == m) {
                    y--;
                    x++;
                    isRerverse = 1;
                }
            } else {
                y--;

                if (y == -1) {
                    y++;
                    x++;
                    isRerverse = 0;
                }
            }

            curD++;
        }

        if (curD >= n * m) {
            break;
        }

        if (isExist[x][y]) {
            continue;
        } else {
            break;
        }
    }

    cout << cnt << endl;

}