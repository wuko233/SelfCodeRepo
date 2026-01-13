#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0;
    vector<int> num(n);
    unordered_set<int> numSet;  // 哈希集

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        numSet.insert(num[i]);
    }

    vector<bool> isSatisfy(30000, false);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = num[i] + num[j];
            if (numSet.find(sum) != numSet.end()) {
                isSatisfy[sum] = true;
            }
        }
    }
    
    for (int i: num) {
        if (isSatisfy[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;
}