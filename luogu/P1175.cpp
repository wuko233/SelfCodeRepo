#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

using ll = long long;

int priority(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

ll calculate(ll first, ll second, char c) {
    switch (c) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return first / second;
        case '^': {
            ll res = 1;
            for (ll i = 0; i < second; i++) {
                res *= first;
            }
            return res;
        }
    }
    return 0;
}

void print_ans(const stack<ll>& s, const vector<string>& ans, int start_pos) {
    stack<ll> temp = s;
    vector<ll> nums;
    
    while (!temp.empty()) {
        nums.push_back(temp.top());
        temp.pop();
    }
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        cout << nums[i] << " ";
    }
    
    for (size_t i = start_pos; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    string line;
    getline(cin, line);
    
    stack<char> compute;
    vector<string> ans;
    
    for (char ch : line) {
        if (isdigit(ch)) {
            ans.push_back(string(1, ch));
        } 
        else if (ch == '(') {
            compute.push(ch);
        }
        else if (ch == ')') {
            while (!compute.empty() && compute.top() != '(') {
                ans.push_back(string(1, compute.top()));
                compute.pop();
            }
            if (!compute.empty() && compute.top() == '(') {
                compute.pop();
            }
        }
        else {
            while (!compute.empty() && compute.top() != '(') {
                if (ch == '^') {
                    if (priority(compute.top()) > priority(ch)) {
                        ans.push_back(string(1, compute.top()));
                        compute.pop();
                    } else {
                        break;
                    }
                } else {
                    if (priority(compute.top()) >= priority(ch)) {
                        ans.push_back(string(1, compute.top()));
                        compute.pop();
                    } else {
                        break;
                    }
                }
            }
            compute.push(ch);
        }
    }
    
    while (!compute.empty()) {
        ans.push_back(string(1, compute.top()));
        compute.pop();
    }
    
    for (const string& s : ans) {
        cout << s << " ";
    }
    cout << endl;
    
    stack<ll> s;
    for (size_t i = 0; i < ans.size(); i++) {
        string cur = ans[i];
        
        if (isdigit(cur[0])) {
            s.push(cur[0] - '0');
        } else {
            ll second = s.top(); s.pop();
            ll first = s.top(); s.pop();
            ll result = calculate(first, second, cur[0]);
            s.push(result);
            
            if (i < ans.size() - 1) {
                print_ans(s, ans, i + 1);
            }
        }
    }
    
    cout << s.top() << endl;
    
    return 0;
}