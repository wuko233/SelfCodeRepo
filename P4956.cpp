#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int perWeek = n / 52;

    // perWeek = 7 * x + k * 21
    for (int x = 100; x > 0; x--) {
        if ((perWeek - 7 * x) % 21 == 0 ) {
            int k = (perWeek - 7 * x) / 21;
            if (k <= 0) continue;
            cout << x << endl << k << endl;
            break;
        }
    }
}