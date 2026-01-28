#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> arr;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        long long b;
        cin >> b;

        cout << arr[b - 1] << endl;
    }
}