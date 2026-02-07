#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

bool isPossible(const vector<ll>& plents, ll height, int w, int k) {
    vector<ll> diffArr(plents.size() + 2, 0);

    ll curAdd = 0;
    ll totalUsed = 0;

    for (size_t i = 0; i < plents.size(); ++i) {
        curAdd += diffArr[i];
        ll h = plents[i] + curAdd;
       
        if (h < height) {
            ll diff = height - h;
            totalUsed += diff;
            if (totalUsed > k) {
                return false;
            }
            diffArr[i] += diff;
            diffArr[min(i + w, plents.size())] -= diff;
            curAdd += diff;
        }
    }

    return true;
}


int main() {
    int n, k, w;
    cin >> n >> k >> w;

    vector<ll> plents(n);

    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;

        plents[i] = h;
    }

    ll lowestHeight = *min_element(plents.begin(), plents.end());
    ll maxHeight = lowestHeight + k;
    ll ans = lowestHeight;

    while (lowestHeight <= maxHeight) {
        ll midHeight = lowestHeight + (maxHeight - lowestHeight) / 2;
        if (isPossible(plents, midHeight, w, k)) {
            ans = midHeight;
            lowestHeight = midHeight + 1;
        } else {
            maxHeight = midHeight - 1;
        }
    }

    cout << ans << endl;
}