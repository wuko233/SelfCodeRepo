#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int maxLength = 0;
    int rightLength = 0;
    int last = -1;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (last == -1) {
            last = a;
            continue;
        }
        if (last + 1 == a) {
            rightLength++;
        } else {
            rightLength = 0;
        }
        last = a;
        if (rightLength > maxLength) {
            maxLength = rightLength;
        }
    }

    cout << maxLength + 1 << endl;
}