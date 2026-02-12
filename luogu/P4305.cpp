#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        unordered_set<int> s;
        vector<int> v;

        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (s.find(x) == s.end()) {
                s.insert(x);
                v.push_back(x);
            }
        }

        for (int a: v) {
            cout << a << " ";
        }
        cout << endl;

    }

}