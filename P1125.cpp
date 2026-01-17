#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);

    unordered_map<char, int> charCount;

    for (char ch: s) {
        if (ch == ' ') continue;
        charCount[ch]++;
    }

    vector<pair<char, int>> vec(charCount.begin(), charCount.end());

    sort(vec.begin(), vec.end(), 
        [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        }
    );

    int maxCount = vec[0].second;
    int minCount = vec.back().second;
    
    int diff = maxCount - minCount;

    if (isPrime(diff)) {
        cout << "Lucky Word" << endl;
        cout << diff << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }



}