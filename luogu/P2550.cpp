#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isGetPrice(int n, vector<int> price) {
    for (int p: price) {
        if (n == p) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> price(8);
    unordered_map<int, int> gotPrice;

    for (int i = 1; i <= 7; i++) {
        cin >> price[i];
        gotPrice[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int ii = 1; ii <= 7; ++ii) {
            int caipiao;
            cin >> caipiao;
            if (isGetPrice(caipiao, price)) cnt++;
        }
        gotPrice[cnt]++;
    }

    for (int i = 7; i > 0; --i) {
        cout << gotPrice[i] << " ";
    }
        
}