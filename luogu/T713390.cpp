#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> sleepDays = {
        {"Great", 0},
        {"Good", 0},
        {"Bad", 0}
    };

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a < 12) {
            if (a >= 9) {
            sleepDays["Great"]++;
            } else if (a >= 5) {
                sleepDays["Good"]++;
            } else {
                sleepDays["Bad"]++;
            }
        }
    }

    if (sleepDays["Bad"] > 0) {
        cout << "Bad" << endl;
        cout << sleepDays["Bad"] << endl;
    } else if (sleepDays["Good"] > 0) {
        cout << "Good" << endl;
        cout << sleepDays["Good"] << endl;
    } else {
        cout << "Great" << endl;
        cout << sleepDays["Great"] << endl;
    }
}