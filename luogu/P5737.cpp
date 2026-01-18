#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int x, y;
    cin >> x >> y;

    vector<int> results;
    int cnt = 0;

    for (int i = x; i <= y; i++) {
        if (isLeapYear(i)) {
            results.push_back(i);
            cnt++;
        }
    }

    cout << cnt << endl;
    for (int year : results) {
        cout << year << " ";
    }
}