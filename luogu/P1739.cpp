#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    cin >> line;

    stack<char> s;

    for (char c : line) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                cout << "NO" << endl;
                return 0;
            } else {
                s.pop();
            }        
        }
    }

    if (s.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}