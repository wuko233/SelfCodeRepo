#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    while (n != 0) {
        arr.push_back(n);
        cin >> n;
    }

    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " ";
    }
}