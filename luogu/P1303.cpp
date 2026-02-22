#include <iostream>
#include <string>

using namespace std;

string signalMultiply(string a, int b) {
    string result;
    int carry = 0;

    int aLen = a.length();

    for (int i = 0; i < aLen; ++i) {
        int digit = a[aLen - 1 - i] - '0';
        int temp = digit * b + carry;
        result = to_string(temp % 10) + result;
        carry = temp / 10;
    }
    if (carry > 0) {
        result = to_string(carry) + result;
    }

    return result;
}

string largeAdd(string a, string b) {
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

    return result;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (a == "0" || b == "0") {
        cout << "0" << endl;
        return 0;
    }

    string result;
    for (int i = b.length() - 1; i >= 0; --i) {
        int digit = b[i] - '0';
        string t = signalMultiply(a, digit);
        t += string(b.length() - 1 - i, '0');
        result = largeAdd(result, t);
    }

    cout << result << endl;
}