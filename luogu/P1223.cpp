#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Person {
    int id;
    int time;
};

bool comparePersons(const Person& a, const Person& b) {
    if (a.time == b.time) {
        return a.id < b.id;
    }
    
    return a.time < b.time;
}

int main() {
    int n;
    cin >> n;

    vector<Person> persons;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;

        Person p = {i + 1, t};

        persons.push_back(p);
    }

    sort(persons.begin(), persons.end(), comparePersons);
    
    for (int i = 0; i < n; ++i) {
        cout << persons[i].id << " ";
    }
    cout << endl;

    double totalTime = 0.0;
    double prefixSum = 0.0;

    for (Person p : persons) {
        totalTime += prefixSum;
        prefixSum += p.time;
    }

    double avgTime = totalTime / n;
    cout << fixed << setprecision(2) << avgTime << endl;
}