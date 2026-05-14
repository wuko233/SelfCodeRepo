#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

int gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;


    for (int i = 0; i < T; ++i) {
        long long a, b;
        cin >> a >> b;

        vector<long long> gongyue;

        for (long long i = gcd(a, b); i >= 1; --i) {
            if (a % i == 0 && b % i == 0) {
                gongyue.push_back(i);
            }
            if (gongyue.size() >= 3) {
                break;
            }
        }

        if (gongyue.size() < 3) {
            cout << -1 << endl;
        } else {
            cout << gongyue[2] << endl;
        }
    }
}