#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, m;
    cin >> n >> m;

    vector<string> titles(m);

    for (int i = 0; i < m; ++i) {
        string title;
        cin >> title;

        titles[i] = title;
    }

    string prefix = "freopen(\"";
    string suffix = ",stdin);";

    string emptyLine;
    getline(cin, emptyLine);
    
    for (int i = 0; i < n; ++i) {
        getline(cin, emptyLine);

        int isNormal = 1; // 1: 普通人, 0: 乐子人, -1: 见祖宗人

        for (int j = 0; j < m; ++j) {
            string curTitle = titles[j];

            string line1, line2;
            getline(cin, line1);
            getline(cin, line2);
            
            if ((line1.compare(0, 10, "//freopen(") == 0 && line1.compare(line1.size() - 2, line1.size(), ");") == 0) || 
                (line2.compare(0, 10, "//freopen(") == 0 && line2.compare(line2.size() - 2, line2.size(), ");") == 0)) {
                isNormal = -1;
            }
            
            if (isNormal == -1) continue;
            
            string inCommand = prefix + curTitle + ".in\",\"r\",stdin);";
            string outCommand = prefix + curTitle + ".out\",\"w\",stdout);";
            
            if (line1 != inCommand || line2 != outCommand) {
                isNormal = 0;
            }
        }

        if (isNormal == -1) {
            cout << "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI." << endl;
        } else if (isNormal == 0) {
            cout << "Good luck and have fun." << endl;
        } else {
            cout << "PION5202 RP++." << endl;
        }

    }
}