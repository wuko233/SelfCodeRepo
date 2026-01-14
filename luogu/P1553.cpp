#include <iostream>

using namespace std;

string justReverse(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    return s;
}

string reverseInteger(string s) {
    if (s == "0") {
        return s;
    }
    s = justReverse(s);
    bool leadingZero = true;
    string result = "";
    for (char c : s) {
        if (leadingZero && c == '0') {
            continue;
        }
        leadingZero = false;
        result += c;
    }

    return result;
}

string reverseDecimal(string s) {
    // 对于小数翻转而言，其小数点前面部分同上，
    //小数点后面部分的形式，保证满足小数的常见形式，也就是末尾没有多余的 0
    //（小数部分除了 0 没有别的数，那么只保留 1 个 0。
    // 若反转之后末尾数字出现 0，请省略多余的 0）
    int dotPos = s.find('.');
    string intPart = s.substr(0, dotPos);
    string decPart = s.substr(dotPos + 1);

    intPart = reverseInteger(intPart);
    decPart = justReverse(decPart);

    bool trailingZero = true;
    string newDecPart = "";
    for (int i = decPart.length() - 1; i >= 0; i--) {
        if (trailingZero && decPart[i] == '0') {
            continue;
        }
        trailingZero = false;
        newDecPart = decPart[i] + newDecPart;
    }

    if (newDecPart == "") {
        newDecPart = "0";
    }

    return intPart + '.' + newDecPart;
}

string reverseFraction(string s) {
    int slashPos = s.find('/');
    string numerator = s.substr(0, slashPos);
    string denominator = s.substr(slashPos + 1);

    numerator = reverseInteger(numerator);
    denominator = reverseInteger(denominator);

    return numerator + '/' + denominator;
}

string reversePercentage(string s) {
    string numberPart = s.substr(0, s.length() - 1);
    numberPart = reverseInteger(numberPart);
    return numberPart + '%';
}

int main() {
    string s;
    getline(cin, s);

    if (s.find('/') != string::npos) {
        cout << reverseFraction(s) << endl;
    } else if (s.back() == '%') {
        cout << reversePercentage(s) << endl;
    } else if (s.find('.') != string::npos) {
        cout << reverseDecimal(s) << endl;
    } else {
        cout << reverseInteger(s) << endl;
    }

}