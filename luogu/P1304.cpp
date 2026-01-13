#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 4; i <= n; i+=2) {
        for (int j = 2; j <= i / 2; j++) {
            if (isPrime(j) && isPrime(i - j))  {
                cout << i << '=' << j << '+' << (i - j) << endl;
                break;
            }
        }
    }

    return 0;
}