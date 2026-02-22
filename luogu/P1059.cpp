#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;

    unordered_set<int> unique_numbers;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (unique_numbers.find(a) == unique_numbers.end()) {
            arr.push_back(a);
            unique_numbers.insert(a);
        }
            
    }

    sort(arr.begin(), arr.end());

    cout << arr.size() << endl;

    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
}