#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    
    sort(prices.begin(), prices.end());
    
    long long count = 0;
    long long cost = 0;
    
    for (int i = 0; i < n; ++i) {
        if (cost + prices[i] <= m) {
            cost += prices[i];
            count++;
        } else {
            break;
        }
    }
    
    cout << count << " " << cost << endl;
    
    return 0;
}