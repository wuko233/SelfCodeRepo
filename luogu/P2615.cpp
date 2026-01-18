#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int huanCube[n+1][n+1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            huanCube[i][j] = 0;
        }
    }

    huanCube[1][n/2 + 1] = 1;
    int lastX = 1, lastY = n/2 + 1;
    for (int k = 2; k <= n * n; ++k) {
        int nowX, nowY;
        if (lastX == 1) {

            if (lastY != n) {
                nowX = n;
                nowY = lastY + 1;
            } else {
                nowX = lastX + 1;
                nowY = lastY;
            }
        } else if (lastY == n) {
            nowY = 1;
            nowX = lastX - 1;
        } else {
            if (huanCube[lastX - 1][lastY + 1] == 0) {
                nowX = lastX - 1;
                nowY = lastY + 1;
            } else {
                nowX = lastX + 1;
                nowY = lastY;
            }
        }

        huanCube[nowX][nowY] = k;
        lastX = nowX;
        lastY = nowY;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << huanCube[i][j];
            if (j != n) cout << " ";
        }
        cout << endl;
    }
}