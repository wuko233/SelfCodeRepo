#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    queue<int> dic;
    unordered_set<int> exist;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        int word;
        cin >> word;

        if (exist.find(word) == exist.end()) {
            cnt++;

            if (dic.size() == m) {
                int front = dic.front();
                dic.pop();
                exist.erase(front);
            }

            dic.push(word);
            exist.insert(word);
        }
    }

    cout << cnt << endl;
}
