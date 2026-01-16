#include <iostream>

using namespace std;

struct Student {
    string name;
    int chinese;
    int math;
    int english;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    int maxSum = -1;
    struct Student topStudent;

    for (int i = 0; i < n; i++) {
        string name;
        int chinese, math, english;
        cin >> name >> chinese >> math >> english;
        int total = chinese + math + english;
        if (total > maxSum) {
            maxSum = total;
            topStudent.name = name;
            topStudent.chinese = chinese;
            topStudent.math = math;
            topStudent.english = english;
        }
    }

    cout << topStudent.name << " " << topStudent.chinese << " " << topStudent.math << " " << topStudent.english << endl;
}