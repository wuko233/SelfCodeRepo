#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    int stree[2000000] = {0};

    for (int i = 0; i < n; i++) {
        int t;
        double a;
        cin >> a >> t;

        for (int j = 1; j <= t; j++) {
            int pos = (int)(a * j);
            stree[pos] ^= 1;
        }
            
    }

    for (int i = 0; i < 2000000; i++) {
        if (stree[i]) {
            cout << i;
            break;
        }
    }

}