#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> prefixArr(n+1);
    prefixArr[0] = 0;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        prefixArr[i] = prefixArr[i-1] + a;
    }

    vector<long long> diffArr(n+2, 0);

    for (int i = 0; i < m; ++i) {
        int l, r, c;
        cin >> l >> r >> c;

        diffArr[l] += c;
        diffArr[r+1] -= c;
    }

    vector<long long> addArr(n+1, 0);
    long long curAdd = 0;

    for (int i = 1; i <= n; ++i) {
        curAdd += diffArr[i];
        addArr[i] = curAdd;
    }

    vector<long long> addPrefixArr(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        addPrefixArr[i] = addPrefixArr[i-1] + addArr[i];
    }

    for (int i = 1; i <= n; ++i) {
        prefixArr[i] += addPrefixArr[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        cout << prefixArr[r] - prefixArr[l-1] << endl;
    }

}