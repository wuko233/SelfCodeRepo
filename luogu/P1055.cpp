#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int number[10] = {0};
    int idx = 0;
    int cnt = 0;
    int identify = 0;
    for (char &c : s)  {
        if (c == '-') {
            cnt++;
            continue;
        }
        if (cnt == 3) {
            if (c == 'X') {
                identify = 10;
                break;
            }
            identify = c - '0';
            break;
        }
        
        number[idx++] = c - '0';
    }

    int rightIdentify = 0;
    for (int i = 0; i < 9; i++) {
        rightIdentify += (i + 1) * number[i];
    }
    rightIdentify %= 11;
    if (rightIdentify == identify) {
        cout << "Right" << endl;
    } else {
        if (rightIdentify == 10) {
            cout << s.substr(0, s.size() - 1) + "X" << endl;
            return 0;
        }
        cout << s.substr(0, s.size() - 1) << rightIdentify << endl;  
    }
}