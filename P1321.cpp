#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int boy = 0;
    int girl = 0;


    for (int i = 0; i < s.size() - 1; ++i) {
        char c = s[i];

        if (c == '.') continue;
        if (c == 'b') boy++;
        if (c == 'g') girl++;

        if (c == 'o') {
            if (s[i-1] != 'b') boy++;
        }

        if (c == 'y') {
            if (s[i-1] != 'o') boy++;
        }

        if (c == 'i') {
            if (s[i-1] != 'g') girl++;
        }
        if (c == 'r') {
            if (s[i-1] != 'i') girl++;
        }
        if (c == 'l') {
            if (s[i-1] != 'r') girl++;
        }
    }

    cout << boy << endl << girl;
}