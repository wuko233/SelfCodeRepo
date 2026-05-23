#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<char>> grid(12, vector<char>(12, '*'));

    pair<int, int> f_pos, c_pos;

    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cin >> grid[i][j];

            if (grid[i][j] == 'F') {
                f_pos = {i, j};
            } else if (grid[i][j] == 'C') {
                c_pos = {i, j};
            }
        }
    }

    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int times = 0, f_dir = 0, c_dir = 0;
    while (f_pos != c_pos) {
        char curr_f = grid[f_pos.first][f_pos.second];
        char next_f = grid[f_pos.first + dir[f_dir][0]][f_pos.second + dir[f_dir][1]];
        if (next_f == '*') {
            f_dir = (f_dir + 1) % 4;
        } else {
            f_pos.first += dir[f_dir][0];
            f_pos.second += dir[f_dir][1];
        }

        char curr_c = grid[c_pos.first][c_pos.second];
        char next_c = grid[c_pos.first + dir[c_dir][0]][c_pos.second + dir[c_dir][1]];
        if (next_c == '*') {
            c_dir = (c_dir + 1) % 4;
        } else {
            c_pos.first += dir[c_dir][0];
            c_pos.second += dir[c_dir][1];
        }

        times++;

        if (times > 10*10*4*10*10*4) {
            times = 0;
            break;
        }
    }

    cout << times << endl;
}