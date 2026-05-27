#include <iostream>
#include <stack>

using namespace std;

using ll = long long;

int main() {
    stack<ll> s;
    char c;
    ll res = 0;

    ll cur_num = 0;
    ll last_cmd = '+';
    char state = '+';

    while((c = getchar()) != EOF && c != '\n') {
        if (isdigit(c)) {
            cur_num = (cur_num * 10 + (c - '0')) % 10000;
        } else {
            if (last_cmd == '+') {
                s.push(cur_num);
            } else if (last_cmd == '*') {
                ll last_num = s.top();
                s.pop();
                s.push((last_num * cur_num) % 10000);
            }

            cur_num = 0;
            last_cmd = c;
        }
    }

    if (last_cmd == '+') {
        s.push(cur_num);
    } else if (last_cmd == '*') {
        ll last_num = s.top();
        s.pop();
        s.push((last_num * cur_num) % 10000);
    }

    while (!s.empty()) {
        res += s.top() % 10000;
        s.pop();
    }

    cout << res % 10000 << endl;
}