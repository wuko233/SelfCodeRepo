#include <iostream>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    int cnt = 0;

    vector<vector<char>> keyboard;
    keyboard.push_back({'a', 'd', 'g', 'j', 'm', 'p', 't', 'w', ' '});
    keyboard.push_back({'b', 'e', 'h', 'k', 'n', 'q', 'u', 'x'});
    keyboard.push_back({'c', 'f', 'i', 'l', 'o', 'r', 'v', 'y'});
    keyboard.push_back({'s', 'z'});

    for (char ch: line) {
        for (int i = 0; i < keyboard.size(); i++) {
            for (int j = 0; j < keyboard[i].size(); j++) {
                if (keyboard[i][j] == ch) {
                    cnt += i + 1;
                }
            }
        }
    }

    cout << cnt << endl;
}