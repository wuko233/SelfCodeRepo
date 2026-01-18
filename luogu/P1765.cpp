#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    int cnt = 0;
    
    unordered_map<char, int> keyboard = {
        {'a',1}, {'b',2}, {'c',3}, {'d',1}, {'e',2}, {'f',3}, {'g',1}, {'h',2}, {'i',3},
        {'j',1}, {'k',2}, {'l',3}, {'m',1}, {'n',2}, {'o',3}, {'p',1}, {'q',2}, {'r',3},
        {'s',4}, {'t',1}, {'u',2}, {'v',3}, {'w',1}, {'x',2}, {'y',3}, {'z',4}, {' ',1}
    };

    for (char c : line) {
        cnt += keyboard[c];
    }

    cout << cnt << endl;
}