#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 1;

    for (int i = n - 1; i > 0; i--) {
        cnt = (cnt + 1) * 2;
    }

    cout << cnt << endl;
}