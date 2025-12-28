#include <iostream>
#include <cstdlib>
using namespace std;

char s[100000];
int cnt = 0;

template<typename T>
T abs(T a, T b) {
    return a < 0 ? -a : a;
}

void game(int target) {
    int a = 0, b = 0;
    
    for (int i = 0; i < cnt; i++) {
        if (s[i] == 'W') a++;
        if (s[i] == 'L') b++;
        
        if (s[i] == 'E') {
            cout << a << ":" << b << endl;
            return;
        }
        
        if ((a >= target || b >= target) && abs(a - b) >= 2) {
            cout << a << ":" << b << endl;
            a = b = 0;
        }
    }
}

int main() {
    char c;

    while ((c = getchar()) != EOF) {
        s[cnt++] = c;
        if (c == 'E') break;
    }
    
    game(11);
    cout << endl;
    game(21);
    
    return 0;
}