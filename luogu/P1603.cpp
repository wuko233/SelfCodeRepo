#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<string> sentence;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        sentence.push_back(word);
    }

    vector<string> words = {
    "one", "two", "three", "four", "five", 
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
    };

    vector<string> result;

    for (string &w: sentence) {
        if (w == "a" || w == "another" || w == "first") {
            result.push_back("01");
            continue;
        } else if (w == "both" || w == "second") {
            result.push_back("04");
            continue;
        } else if (w == "third") {
            result.push_back("09");
            continue;
        }
        for (int i = 0;i < words.size(); i++) {
            if (w == words[i]) {
                int num = (i+1)*(i+1)%100;
                if (num < 10) {
                    result.push_back("0" + to_string(num));
                } else {
                    result.push_back(to_string(num));
                }
                continue;
            }
        }
    }
    
    sort(result.begin(), result.end());

    bool isHeading = true;
    string ans = "";
    for (int i = 0; i < result.size(); i++) {
        if (isHeading) {
            if (result[i] == "00") {
                continue;
            } else if (result[i][0] == '0') {
                isHeading = false;
                ans += result[i][1];
                continue;
            } 
        }
        isHeading = false;
        ans += result[i];
    }

    if (ans == "") {
        ans = "0";
    }

    cout << ans << endl;
}