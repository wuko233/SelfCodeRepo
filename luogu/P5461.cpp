#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#include <vector>
using namespace std;

void shemian(vector<vector<int>>& arr, int row, int col) {
    if (row <= 1 || col <= 1) {
        return;
    }
    
    // 左上角清零
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            arr[i][j] = 0;
        }
    }
    
    // 处理左下部分
    vector<vector<int>> part1(row / 2, vector<int>(col / 2));
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            part1[i][j] = arr[i + row / 2][j];
        }
    }
    shemian(part1, row / 2, col / 2);
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            arr[i + row / 2][j] = part1[i][j];
        }
    }
    
    // 处理右上部分
    vector<vector<int>> part2(row / 2, vector<int>(col / 2));
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            part2[i][j] = arr[i][j + col / 2];
        }
    }
    shemian(part2, row / 2, col / 2);
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            arr[i][j + col / 2] = part2[i][j];
        }
    }
    
    // 处理右下部分
    vector<vector<int>> part3(row / 2, vector<int>(col / 2));
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            part3[i][j] = arr[i + row / 2][j + col / 2];
        }
    }
    shemian(part3, row / 2, col / 2);
    for (int i = 0; i < row / 2; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            arr[i + row / 2][j + col / 2] = part3[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cheaters((int)pow(2,n), vector<int>((int)pow(2,n)));
    for (int i = 0; i < (int)pow(2,n); ++i) {
        for (int j = 0; j < (int)pow(2,n); ++j) {
            cheaters[i][j] = 1;
        }
    }
    shemian(cheaters, (int)pow(2,n), (int)pow(2,n));

    for (int i = 0; i < (int)pow(2,n); ++i) {
        for (int j = 0; j < (int)pow(2,n); ++j) {
            cout << cheaters[i][j];
            if (j != (int)pow(2,n) - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}