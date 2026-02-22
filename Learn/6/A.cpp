#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x > y) {
        cout << "NO" << endl;
    } else if (x == y) {
        cout << "equal probability" << endl;
    } else {
        cout << "YES" << endl;
    }
}