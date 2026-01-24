#include <iostream>

using namespace std;

bool isSushu(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i <= n; ++i) {
            if (isSushu(i)) {
                cout << i << endl;
            }
        }
    }
    
}