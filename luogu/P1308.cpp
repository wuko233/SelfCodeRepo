#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

string tolowercase(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

int main() {
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    s1 = tolowercase(s1);
    s2 = tolowercase(s2);

    int i = 0;
    int s1Len = s1.length();
    int s2Len = s2.length();

    int cnt = 0;
    int pos = -1;
    
    for (int i = 0; i <= s2Len; i++) {
        if (s2[i] == ' ' ) continue;

        if (i > 0 && s2[i - 1] != ' ') continue;

        bool match = true;

        for (int j = 0; j < s1Len; j++) {
            if (i + j >= s2Len || s2[i + j] != s1[j]) {
                match = false;
                break;
            }
        }

        if (match && (i + s1Len == s2Len || s2[i + s1Len] == ' ')) {
            cnt++;
            if (pos == -1) {
                pos = i;
            }
        }

        while (i < s2Len && s2[i] != ' ') {
            i++;
        }
    }

    // stringstream ss2(s2);
    // string token = " ";
    // vector<string> tokens;

    // while (ss2 >> token) {
    //     tokens.push_back(token);
    // }

    // int cnt = 0;
    // int pos = -1;
    // int tempPos = 0;
    // for (const string& t : tokens) {
    //     if (s1 == t) {
    //         if (cnt == 0) pos = tempPos;
    //         cnt++;
    //     }
    //     tempPos += t.size() + 1;
    // }

    if (pos == -1) {
        cout << pos << endl;
    } else {
        cout << cnt << " " << pos << endl;
    }
}