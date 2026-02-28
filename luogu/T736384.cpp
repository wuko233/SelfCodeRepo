#include <iostream>

using namespace std;

char yuanyin[] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        string res = "";

        bool isPartEnd = true;
        for (char ch: s) {
            if (isPartEnd) {
                res += ch - 'a' + 'A';
                isPartEnd = false;
            }

            for (char y: yuanyin) {
                if (y == ch) {
                    isPartEnd = true;
                    break;
                }
            }
        }

        cout << res << endl;

    }
}