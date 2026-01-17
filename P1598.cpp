#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    map<char, int> charCount;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        charCount[ch] = 0;
    }

    for (int i = 0; i < 4; ++i) {
        string s;
        getline(cin, s);

        for (char c : s) {
            if (c >= 'A' && c <= 'Z')
            charCount[c]++;
        }
    }

    int maxLength = 0;
    for (const auto& pair : charCount) {
        maxLength = max(maxLength, pair.second);
    }

    char output[26][maxLength + 1];
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j <= maxLength; ++j) {
            output[i][j] = ' ';
        }
    }

    for (int ch = 'A'; ch <= 'Z'; ++ch) {
        int i = ch - 65;
        output[i][0] = (char) ch;
        for (int ii = 1; ii <= charCount[(char) ch]; ++ii) {
            output[i][ii] = '*';
        }
    }

    for (int j = maxLength; j >= 0; --j) {
        cout << output[0][j];
        for (int i = 1; i < 26; ++i) {
            cout << ' ' << output[i][j];
        }
        cout << endl;
    }
}