#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<bool> matched(n, false);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(i);
        } else {
            if (!st.empty()) {
                int topIdx = st.top();
                if ((s[topIdx] == '(' && s[i] == ')') ||
                    (s[topIdx] == '[' && s[i] == ']')) {
                    matched[topIdx] = matched[i] = true;
                    st.pop();
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (matched[i]) {
            cout << s[i];
        } else {
            if (s[i] == '(') {
                cout << "()";
            } else if (s[i] == ')') {
                cout << "()";
            } else if (s[i] == '[') {
                cout << "[]";
            } else if (s[i] == ']') {
                cout << "[]";
            }
        }
    }
    cout << endl;

    return 0;
}