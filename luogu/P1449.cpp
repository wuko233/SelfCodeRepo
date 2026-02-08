#include <iostream>
#include <stack>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    stack<int> nums;

    string num;
    for (const char &ch: expression) {
        if (ch >= '0' && ch <= '9') {
            num += ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            if (ch == '+') {
                nums.push(num1 + num2);
            } else if (ch == '-') {
                nums.push(num1 - num2);
            } else if (ch == '*') {
                nums.push(num1 * num2);
            } else if (ch == '/') {
                nums.push(num1 / num2);
            }
        } else if (ch == '.') {
            nums.push(stoi(num));
            num = "";
        } else if (ch == '@') break;
    }

    cout << nums.top() << endl;
}