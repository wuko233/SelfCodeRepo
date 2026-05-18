// 999 cirno's math classroom

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

struct Cirno9 {
    int a0, b0, c0, d0;
};


string compute(char op, int &x, int y, int z) {
    int res = 0;
    switch (op) {
        case '+':
            res = y + z;
        case '-':
            res = y - z;
        case '*':
            res = y * z;
        case '/':
            res = y / z;
    }
    x = res;
    return "ok";
}

char compare(int a, int b) {
    if (a > b) return '>';
    else if (a < b) return '<';
    else return '=';
}

int main() {
    double a0, b0, c0, d0;
    double r0 = 0, r1 = 0, r2 = 0, r3 = 0;

    char op;
    int x, y, z;

    cin >> op >> x;

    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
            cin >> y >> z;
            cout << compute(op, x, y, z) << endl;
        case '?':
            cin >> y;
            cout << compare(x, y) << endl;
        case '!':
            
    }
}