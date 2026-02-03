#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int A[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    int B[n][m];

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            int val = A[row][col];
            if (row > 0) val += A[row - 1][col];
            if (col > 0) val += A[row][col - 1];
            if (n - row - 1 > 0) val += A[row + 1][col];
            if (m - col - 1 > 0) val += A[row][col + 1];
            B[row][col] = val;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}