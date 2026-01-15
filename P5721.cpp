#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int enter = 0;
    for (int i = 1;; i++) {
        if (n == 0) {
            break;
        }
        string s = to_string(i);
        if (s.length() == 1) {
            s = "0" + s;
        }
        cout << s;
        enter++;
        if (enter == n) {
            enter = 0;
            n--;
            cout << endl;
        }
    }
}