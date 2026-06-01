#include <iostream>
#include <stack>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        if (st.empty()) {
            ans[i] = 0;
            st.push(i);
            continue;
        }

        if (a[st.top()] > a[i]) {
            ans[i] = st.top();
        } else {
            while (!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            } else {
                ans[i] = 0;
            }
        }

        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << (ans[i] == 0?  0:ans[i] + 1) << " ";
    }
}