#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll distance = 0;

    vector<ll> e_idx;
    vector<ll> f_idx;    
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'e') {
            e_idx.push_back(i);
        } else if (s[i] == 'f') {
            f_idx.push_back(i);
        }
    }
    
    for (int i = 0; i < e_idx.size(); i++) {
        for (int j = 0; j < f_idx.size(); j++) {
            if (e_idx[i] > f_idx[j]) continue;

            distance += (f_idx[j] - e_idx[i]);
        }
    }

    cout << distance << endl;
}