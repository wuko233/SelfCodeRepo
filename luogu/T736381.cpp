#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> isOcc(n+1, 0);

    int minUnOcc = n + 1;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        isOcc[i] = a;

        if (a == 0 && minUnOcc > i) {
            minUnOcc = i;
        }
    }


    int id;
    cin >> id;

    if (isOcc[id] == 0) {
        cout << id << endl;
    } else {
        cout << minUnOcc << endl;
    }
}