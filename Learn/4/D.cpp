#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<char> signStack;

    int maxSignDepth = 0;
    int curSignDepth = 0;
    bool isSignStable = true;

    string line;
    cin >> line;

    for (char ch: line) {
        if (ch == '(' || ch == '[' || ch == '{') {
            signStack.push(ch);
            curSignDepth++;
            if (curSignDepth > maxSignDepth) maxSignDepth = curSignDepth;
            continue;
        } else {
            ch = (ch == ')') ? '(' : (ch == ']') ? '[' : '{';
        }


        if (signStack.size() != 0 && ch == signStack.top() ) {
            signStack.pop();
            curSignDepth--;
        } else {
            isSignStable = false;
            break;
        }
    }

    if (isSignStable && signStack.size() == 0) {
        cout << "True" << endl;
        cout << maxSignDepth << endl;
    } else {
        cout << "False" << endl;
    }

}
