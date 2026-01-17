#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int lastSum = 0;
    int minSum = 0;

    vector<int> window(n);

    for (int i = 0; i < n; i++) {
        cin >> window[i];

        if (i < m) {
            lastSum += window[i];
            minSum = lastSum;
        } else {
            lastSum = lastSum - window[i - m] + window[i];
            if (lastSum < minSum) {
                minSum = lastSum;
            }
        }
    }

    cout << minSum << endl;
}