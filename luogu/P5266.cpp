#include <iostream>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main() {
    int q;
    cin >> q;
    unordered_map<string, ll> system;

    for (int i = 0; i <q; ++i) {
        int ord;
        cin >> ord;

        if (ord == 1) {
            string name;
            ll score;
            cin >> name >> score;
            system[name] = score;

            cout << "OK" << endl;
        } else if (ord == 2) {
            string name;
            cin >> name;

            if (system.find(name) != system.end()) {
                cout << system[name] << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else if (ord == 3) {
            string name;
            cin >> name;

            if (system.find(name) != system.end()) {
                system.erase(name);
                cout << "Deleted successfully" << endl;
            } else {
                cout << "Not found" << endl;
            }
        } else if (ord == 4) {
            cout << system.size() << endl;
        }
    }
}