#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

bool isBitSumMultipleOfNumber(ll number, ll thatNum) {
    ll bitSum = 0;

    while (number > 0) {
        bitSum += number % 10;
        number /= 10;
    }

    return bitSum % thatNum == 0;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<ll> ans;

    for (int i = 0; i < n; ++i) {
        ll number;
        cin >> number;

        if (number % m != 0 && isBitSumMultipleOfNumber(number, m)) {
            ans.push_back(number);
        }
    }

    if (ans.empty()) {
        cout << "None";
    } else {
        for (ll number : ans) {
            cout << number << endl;
        }
    }
}