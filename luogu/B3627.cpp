#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll low = 1, high = n;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (mid * mid * mid >= n) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}