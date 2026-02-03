#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> scores;

    for (int i = 0; i < n; ++i) {
        int score;
        cin >> score;

        scores.push_back(score);
    }

    vector<int> diffArr(n + 2, 0);

    for (int i = 0; i < p; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        x--;
        y--;

        diffArr[x] += z;
        diffArr[y+1] -= z;
    }

    int minScore = scores[0] + diffArr[0];
    int diff = 0;

    for (int i = 0; i < n; ++i) {
        diff += diffArr[i];
        scores[i] += diff;

        if (scores[i] < minScore) {
            minScore = scores[i];
        }
    }

    cout << minScore << endl;
}