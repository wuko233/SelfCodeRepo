#include <iostream>

using namespace std;

string zero[5] = {
    "XXX",
    "X.X",
    "X.X",
    "X.X",
    "XXX"
};

string one[5] = {
    "..X",
    "..X",
    "..X",
    "..X",
    "..X"
};

string two[5] = {
    "XXX",
    "..X",
    "XXX",
    "X..",
    "XXX"
};

string three[5] = {
    "XXX",
    "..X",
    "XXX",
    "..X",
    "XXX"
};

string four[5] = {
    "X.X",
    "X.X",
    "XXX",
    "..X",
    "..X"
};

string five[5] = {
    "XXX",
    "X..",
    "XXX",
    "..X",
    "XXX"
};

string six[5] = {
    "XXX",
    "X..",
    "XXX",
    "X.X",
    "XXX"
};

string seven[5] = {
    "XXX",
    "..X",
    "..X",
    "..X",
    "..X"
};

string eight[5] = {
    "XXX",
    "X.X",
    "XXX",
    "X.X",
    "XXX"
};

string nine[5] = {
    "XXX",
    "X.X",
    "XXX",
    "..X",
    "XXX"
};

void copy(string s1[5], string s2[5]) {
    for (int i = 0; i < 5; i++) {
        s1[i] = s2[i];
    }
}

int main() {
    int n;
    cin >> n;

    string result[5];
    int index = 0;

    string s;
    cin >> s;

    for (int d = 0; d < s.length(); ++d) {
        char c = s[d];
        int dig;
        string *num;
        switch (c) {
            case '0':
                dig = 0;
                num = zero;
                break;
            case '1':
                dig = 1;
                num = one;
                break;
            case '2':
                dig = 2;
                num = two;
                break;
            case '3':
                dig = 3;
                num = three;
                break;
            case '4':
                dig = 4;
                num = four;
                break;
            case '5':
                dig = 5;
                num = five;
                break;
            case '6':
                dig = 6;
                num = six;
                break;
            case '7':
                dig = 7;
                num = seven;
                break;
            case '8':
                dig = 8;
                num = eight;
                break;
            case '9':
                dig = 9;
                num = nine;
                break;
        }

        for (int i = 0; i < 5; ++i) {
            result[i] += num[i];
        }
        index += 3;
        if (d == n - 1) continue;
        for (int i = index; i < index + 1; ++i) {
            for (int j = 0; j < 5; ++j) {
                result[j] += ".";
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << result[i] << endl;
    }
}