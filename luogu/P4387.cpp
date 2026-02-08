#include <iostream>
#include <stack>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int len;
        cin >> len;

        vector<ll> pushed;
        vector<ll> poped;

        for (int j = 0; j < len; ++j) {
            ll a;
            cin >> a;
            pushed.push_back(a);
        }

        for (int j = 0; j < len; ++j) {
            ll a;
            cin >> a;
            poped.push_back(a);
        }

        stack<ll> simulator;
        int idx = 0;

        for (const ll &num : pushed) {
            simulator.push(num);

            while (!simulator.empty() && simulator.top() == poped[idx]) {
                simulator.pop();
                idx++;
            }
        }

        if (simulator.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }

    
}