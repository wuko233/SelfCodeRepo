#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> votes(n);

    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    int max_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (votes[i].size() > votes[max_idx].size()) {
            max_idx = i;
        } else if (votes[i].size() == votes[max_idx].size()){
            for (size_t j = 0; j < votes[i].size(); ++j) {
                if ((votes[i][j] - '0') > (votes[max_idx][j] - '0') ) {
                    max_idx = i;
                    break;
                } else if ((votes[i][j] - '0') < (votes[max_idx][j] - '0')) {
                    break;
                }
            }
        }
    }

    cout << max_idx + 1 << endl;
    cout << votes[max_idx] << endl;

}