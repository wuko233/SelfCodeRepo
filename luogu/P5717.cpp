#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    
    if (a + b <= c) {
        cout << "Not triangle" << endl;
        return 0;
    }
    
    bool isRight = false;
    bool isAcute = false;
    bool isObtuse = false;
    bool isIsosceles = false;
    bool isEquilateral = false;
    
    if (a == b && b == c) {
        isEquilateral = true;
    }
    
    if (a == b || b == c || a == c) {
        isIsosceles = true;
    }
    
    int a2 = a * a, b2 = b * b, c2 = c * c;
    
    if (a2 + b2 == c2) {
        isRight = true;
    } else if (a2 + b2 > c2) {
        isAcute = true;
    } else {
        isObtuse = true;
    }
    
    if (isRight) {
        cout << "Right triangle" << endl;
    }
    if (isAcute) {
        cout << "Acute triangle" << endl;
    }
    if (isObtuse) {
        cout << "Obtuse triangle" << endl;
    }
    if (isIsosceles) {
        cout << "Isosceles triangle" << endl;
    }
    if (isEquilateral) {
        cout << "Equilateral triangle" << endl;
    }
    
    return 0;
}