#include <iostream>

using namespace std;

int main() {
    int w, x, h;
    cin >> w >> x >> h;

    int volume = w * x * h;

    bool isRemoved[w + 1][x + 1][h + 1] = { false };

    
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        int x = 0, y = 0, z = 0;
        for (int ii = x1; ii <= x2; ii++) {
            for (int jj = y1; jj <= y2; jj++) {
                for (int kk = z1; kk <= z2; kk++) {
                    if (!isRemoved[ii][jj][kk]) {
                        isRemoved[ii][jj][kk] = true;
                        volume--;
                    }
                }
            }
        }
    }

    cout << volume << endl;
}