#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, b;
    cin >> n >> b;

    vector<ll> heights(n + 1);
    
    for (int i =0; i < n; ++i) {
        ll h;
        cin >> h;

        heights[i] = h;
    }

    sort(heights.begin(), heights.end(), [](ll a, ll b) {return a > b;});

    int res = 0;

    ll sumHeight = 0;
    while (sumHeight < b) {
        sumHeight += heights[res];
        res++;
    }

    cout << res <<endl;

}