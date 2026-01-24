#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    string result;
    for (char c : s) {
        if (c == 'A') {
            result += 'T';
        } else if ( c == 'T') {
            result += 'A';
        } else if ( c == 'C') {
            result += 'G';
        } else if ( c == 'G') {
            result += 'C';
        }
    }

    cout << result << endl;
}