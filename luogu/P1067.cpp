#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string res = "";

    for (int i = n; i >= 0; --i) {
        int t;
        cin >> t;

        string t_str = to_string(t);

        if (t_str == "0") {
            continue;
        }

        if (t_str == "1" && i != 0) {
            t_str = "";
        } else if (t_str == "-1" && i != 0) {
            t_str = "-";
        }

        if (i == n) {
            if (i == 0) {
                res = t_str;
            } else if (i == 1) {
                res = t_str + "x";
            } else {
                res = t_str + "x^" + to_string(i);
            }
        } else {
            if (t_str[0] != '-') {
                res += "+";
            }
            if (i == 0) {
                res += t_str;
            } else if (i == 1) {
                res += t_str + "x";
            }else {
                res += t_str + "x^" + to_string(i);
            }
        }
    }
    cout << res << endl;
}