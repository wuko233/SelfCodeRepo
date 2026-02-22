#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int lenA = a.length();
    int lenB = b.length();

    int carry = 0;

    string result;

    for (int i = 0; i < lenA || i < lenB || carry; ++i) {
        int digitA = (i < lenA) ? a[lenA - 1 - i] - '0' : 0;
        int digitB = (i < lenB) ? b[lenB - 1 - i] - '0' : 0;

        int sum = digitA + digitB + carry;
        carry = sum / 10;

        result = to_string(sum % 10) + result;
    }

    cout << result << endl;
}