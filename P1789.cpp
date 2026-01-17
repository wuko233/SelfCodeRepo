#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    cin.ignore();

    int place[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            place[i][j] = 0;
        }
    }
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        // 火把
        for (int ii = x - 2; ii <= x + 2; ii++) {
            if (ii < 0 || ii >= n) continue;
            for (int jj = y - 2; jj <= y + 2; jj++) {
                if (jj < 0 || jj >= n) continue;
                int xx = abs(x - ii);
                int yy = abs(y - jj);
                
                if (xx + yy <= 2) place[ii][jj] = 1;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        
        // 萤石
        for (int ii = x - 2; ii <= x + 2; ii++) {
            if (ii < 0 || ii >= n) continue;
            for (int jj = y - 2; jj <= y + 2; jj++) {
                if (jj < 0 || jj >= n) continue;
                place[ii][jj] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!place[i][j]) cnt++;
        }
    }

    cout << cnt << endl;
}