#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> score(n);

    for (int i =0; i < n; i++) {
        cin >> score[i];
    }

    double final_score = 0.0;

    sort(score.begin(), score.end());

    for (int i = 1; i < n - 1; i++) {
        final_score += score[i];
    }

    final_score /= (n - 2);

    printf("%.2f\n", final_score);
}