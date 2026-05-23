#include <iostream>
#include <vector>

using namespace std;

int win[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}
};

int main() {
    int n, na, nb;
    cin >> n >> na >> nb;

    vector<int> a(na);
    vector<int> b(nb);

    for (int i = 0; i < na; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; ++i) {
        cin >> b[i];
    }

    int score_a = 0;
    int score_b = 0;

    for (int round = 0; round < n; ++round) {
        score_a += win[a[round % na]][b[round % nb]];
        score_b += win[b[round % nb]][a[round % na]];
    }
    cout << score_a << " " << score_b << endl;
}