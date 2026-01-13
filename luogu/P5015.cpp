#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        char cur = s[i];
        if (cur != ' ' && cur != '\n') {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}