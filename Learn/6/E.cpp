#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll rankIt(vector<ll>& arr, ll i) {
    ll count = 0;
    for (ll x : arr) {
        if (x < i) {
            count++;
        }
    }
    return count + 1;
}

int main() {
    int t;
    cin >> t;

    for (int k = 0; k < t; ++k) {
        int n;
        cin >> n;

        vector<ll> arr(n);

        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            arr[i] = a;
        }

        vector<ll> original = arr;

        sort(arr.begin(), arr.end());

        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        
        for (ll i: original) {
            ll rank = lower_bound(arr.begin(), arr.end(), i) - arr.begin() + 1;
            cout << rank << " ";
        }

        cout << endl;
    }
}