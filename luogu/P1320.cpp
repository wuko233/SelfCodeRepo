#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    int N = line.length();

    vector<int> result;
    result.push_back(N);

    char currentChar = '0';
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (line[i] == currentChar) {
            count++;
        } else {
            result.push_back(count);
            count = 1;
            currentChar = (currentChar == '0') ? '1' : '0';
        }
    }

    for (int i = 1; i < N; i++) {
        getline(cin, line);
        for (int j = 0; j < N; j++) {
            if (line[j] == currentChar) {
                count++;
            } else {
                result.push_back(count);
                count = 1;
                currentChar = (currentChar == '0') ? '1' : '0';
            }
        }
    }

    result.push_back(count);

    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}