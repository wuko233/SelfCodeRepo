#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    string s;
    cin >> s;

    vector<long long> nums;

    for (long long i = 0; i < n; ++i) {
        char ch = s[i];

        if (ch >= '0' && ch <= '9') {
            nums.push_back(i + 1);
        }
            

    }

    long long cnt = 0;
    for (long long i = nums.size() - 1; i > 0; --i) {
        cnt += i;
    }

    cout << cnt << endl;

}