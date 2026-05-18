#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;

    ll odd = 0, even = 0;
    if (a % 2 == 0) {
        even = a;
        odd = b;
    } else {
        odd = a;
        even = b;
    }

    cout << (odd > even ? "1" : "2") << endl;
}