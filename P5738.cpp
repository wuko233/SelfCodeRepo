#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<double> avg_scores(n, 0.0);

    for (int i = 0; i < n; i++) {
        vector<int> scores(m);
        for (int j = 0; j < m; j++) {
            cin >> scores[j];
        }
        sort(scores.begin(), scores.end());
        double sum = 0.0;
        for (int j = 1; j < m - 1; j++) {
            sum += scores[j];
        }
        avg_scores[i] = sum / (m - 2);
    }

    double max_avg = *max_element(avg_scores.begin(), avg_scores.end());
    cout.precision(2);
    cout << fixed << max_avg << endl;
}