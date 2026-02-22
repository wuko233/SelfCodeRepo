#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n, q;
    cin >> n >> q;
    
    vector<vector<ll>> datas(n);
    for (int i = 0; i < n; ++i) {
        ll s;
        cin >> s;
        
        vector<ll> row(s);
        for (int j = 0; j < s; ++j) {
            cin >> row[j];
        }
        datas[i] = row;
    }

    for (int i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        
        x--;
        y--;
        
        cout << datas[x][y] << endl;
    }
    
    return 0;
}