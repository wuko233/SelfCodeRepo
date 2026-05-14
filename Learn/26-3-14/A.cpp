#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;


int main() {
    int T;
    cin >> T;

    vector<double> CleanValues(T + 1);

    for (int i = 1; i <= T; ++i) {
        cin >> CleanValues[i];
    }

    double maxDD = 0;

    double maxVal = CleanValues[1];

    for (int i = 2; i <= T; ++i) {
        double curVal = CleanValues[i];

        if (curVal > maxVal) {
            maxVal = curVal;
        } else {
            double dd = (maxVal - curVal) / maxVal;
            maxDD = max(maxDD, dd);
        }
    }

    cout << fixed << setprecision(8) << maxDD << endl;

}

// int main() {
//     int T;
//     cin >> T;

//     vector<double> CleanValues(T + 1);

//     double maxVal = 0;
//     int idx = 0;

//     for (int i = 1; i <= T; ++i) {
//         double cv;
//         cin >> cv;

//         CleanValues[i] = cv;

//         if (cv > maxVal) {
//             maxVal = cv;
//             idx = i;
//         }
//     }

//     double minVal = maxVal;

//     for (int i = idx; i <= T; ++i) {
//         double curVal = CleanValues[i];

//         if (curVal < minVal) {
//             minVal = curVal;
//         }
//     }

//     double maxDD = (maxVal - minVal) / maxVal;

//     cout << fixed << setprecision(8) << maxDD << endl;
// }
