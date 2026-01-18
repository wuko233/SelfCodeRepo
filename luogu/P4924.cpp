#include <iostream>

using namespace std;

// super crazy Flandrechan's super power code

int main() {
    int n, m;
    cin >> n >> m;

    int matrix[n][n];
    int index = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = index;
            index++;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;

        x--; 
        y--;

        // 顺时针后，i变j, j变-i
        // 逆时针后，i变 -j, j变i

        int temp[2 * r + 1][2 * r + 1];

        // 原始矩阵翻转到临时矩阵 映射：x0 -> a - x + r,y0 -> b - y + r
        for (int a = x - r; a <= x +r; a++) {
            for (int b = y - r; b <= y + r; b++) {
                int ii = a - x + r;
                int jj = b - y + r;
                if (z == 0) {
                    // 顺时针
                    temp[jj][2*r - ii] = matrix[a][b];
                } else {
                    // 逆时针
                    temp[2*r - jj][ii] = matrix[a][b];
                }
            } 
        }

        for (int a = x - r; a <= x + r; a++) {
            for (int b = y - r; b <= y + r; b++) {
                matrix[a][b] = temp[a - x + r][b - y + r];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


}