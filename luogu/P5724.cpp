#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min, max;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i == 0) {
            min = a;
            max = a;
        } else {
            if (a < min) min = a;
            if (a > max) max = a;
        }
    }

    cout << max - min << endl;
}