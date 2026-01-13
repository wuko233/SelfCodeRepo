#include <iostream>

using namespace std;

int main() {
    string order;
    getline(cin, order);

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < order.length(); i++) {
        if (order[i] >= 'a' && order[i] <= 'c') {
            char var = order[i];

            i += 3;

            int value;
            if (order[i] >= '0' && order[i] <= '9') {
                value = order[i] - '0';
            } else {
                char subVar = order[i];
                if (subVar == 'a') value = a;
                else if (subVar == 'b') value = b;
                else if (subVar == 'c') value = c;
            }

            if (var == 'a') a = value;
            else if (var == 'b') b = value;
            else if (var == 'c') c = value;

        }
    }

    cout << a << " " << b << " " << c << endl;
    return 0;

}