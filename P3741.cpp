#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<bool> used(n, false);
    int cnt = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'V' && s[i+1] == 'K') {
            cnt++;
            used[i] = used[i+1] = true;
            i++;
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (!used[i] && !used[i+1]) {
            if ((s[i] == 'V' && s[i+1] == 'V') || (s[i] == 'K' && s[i+1] == 'K')) {
                cnt++;
                break;
            }
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}