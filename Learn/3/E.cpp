#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    unordered_map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        int v;
        cin >> s >> v;
        mp[s] = v;
    }

    cin.ignore();

    for (int i = 0; i < k; ++i) {
        string line;
        getline(cin, line);
        
        string result;
        int pos = 0;
        int length = line.length();

        while (pos < length) {
            auto start = line.find('{', pos);

            if (start == string::npos) {
                result += line.substr(pos);
                break;
            }

            result += line.substr(pos, start - pos);

            auto end = line.find('}', start);

            if (end == string::npos) {
                result += line.substr(start);
                break;
            }

            string key = line.substr(start + 1, end - start - 1);

            if (mp.find(key) != mp.end()) {
                result += to_string(mp[key]);
            } else {
                result += "{"+ key + "}";
            }

            pos = end + 1;  
        }
        
        cout << result << endl;
    }
}