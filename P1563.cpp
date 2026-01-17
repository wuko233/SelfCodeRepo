#include <iostream>

using namespace std;

struct toyHuman {
    // int id;
    int face; // 0向内，1向外
    string major;
    // struct toyHuman* prev; // 顺时针
    // struct toyHuman* next; // 逆时针
};

int main() {
    int n, m;
    cin >> n >> m;

    toyHuman humans[n];

    for (int i = 0; i < n; ++i) {
        int face;
        string major;
        cin >> face >> major;
        
        // humans[i].id = i;
        humans[i].face = face;
        humans[i].major = major;
        // humans[i].next = (i == n - 1) ? nullptr : &humans[i + 1];
        // humans[i].prev = (i == 0) ? nullptr : &humans[i - 1];
    }
    // humans[0].prev = &humans[n - 1];
    // humans[n - 1].next = &humans[0];

    int now = 0;
    for (int i = 0; i < m; ++i) {
        int a, s; // 0左，1右
        cin >> a >> s;

        int face = humans[now].face;
        // if (face == a) {
        //     for (int cnt = 0; cnt < s; ++cnt) {
        //         now = humans[now].prev->id;
        //     }
        // } else {
        //     for (int cnt = 0; cnt < s; ++cnt) {
        //         now = humans[now].next->id;
        //     }
        // }

        if (face ^ a) {
            now = (now + s) % n;
        } else {
            now = (now - s + n) % n;
        }
    }

    cout << humans[now].major << endl;
}