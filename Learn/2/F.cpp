#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Character {
    string name;
    long long skill;

    Character(string n, long long s) : name(n), skill(s) {}
};

bool compareBySkill(const Character &a, const Character &b) {
    return a.skill > b.skill;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Character> survivors;
    vector<Character> hunters;

    for (int i = 0; i < n + m; i++) {
        string name;
        char type;
        long long skill;

        cin >> name >> type >> skill;

        if (type == 'S') {
            survivors.push_back(Character(name, skill));
        } else if (type == 'H') {
            hunters.push_back(Character(name, skill));
        }
    }

    sort(survivors.begin(), survivors.end(), compareBySkill);
    sort(hunters.begin(), hunters.end(), compareBySkill);

    cout << hunters[2].name << endl;

    for (int i = 5; i < 9; i++) {
        cout << survivors[i].name << endl;
    }
        
    return 0;
}