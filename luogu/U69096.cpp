#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prefixArr;

    prefixArr.push_back(0);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        prefixArr.push_back(a);
    }

    vector<int> arr;

    for (int i = 0; i < n; ++i) {
        int a = prefixArr[i + 1] - prefixArr[i];
        arr.push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

}