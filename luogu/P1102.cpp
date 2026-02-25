#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> arr;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    long long cnt = 0;

    for (int b: arr) {
        int target = b + c;

        auto leftIt = lower_bound(arr.begin(), arr.end(), target);
        auto rightIt = upper_bound(arr.begin(), arr.end(), target);

        if (leftIt != arr.end() && *leftIt == target) {
            cnt += (rightIt - leftIt);
        }
    }

    cout << cnt << endl;
}