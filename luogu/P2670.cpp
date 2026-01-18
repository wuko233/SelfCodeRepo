#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore(); // 别忘了


    char mines[n][m];

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < m; j++) {
            mines[i][j] = line[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mines[i][j] != '*') {
                int cnt = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        int ni = i + x;
                        int nj = j + y;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && mines[ni][nj] == '*') {
                            cnt++;
                        }
                    }
                }
                cout << cnt;
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }
}