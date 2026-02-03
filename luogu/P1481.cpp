#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> uniqueWords;

    int maxLength = 0;
    

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        
        int cnt = 1;

        for (int i = 1; i < word.length(); ++i) {
            string prefix = word.substr(0, i);
            if (uniqueWords.count(prefix)) {
                cnt = max(cnt, uniqueWords[prefix] + 1);
            }
        }

        uniqueWords[word] = cnt;
        maxLength = max(maxLength, cnt);
    }

    cout << maxLength << endl;
}