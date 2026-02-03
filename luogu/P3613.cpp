#include <iostream>
#include <unordered_map>
#include <functional>

using namespace std;

struct location {
    int x, y;

    bool operator==(const location &other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template<>
    struct hash<location> {
        size_t operator()(const location &loc) const noexcept {
            return hash<int>()(loc.x) ^ (hash<int>()(loc.y) << 1);
        }
    };
};

int main() {
    int n, q;
    cin >> n >> q;

    unordered_map<location, int, hash<location>> loc_map;

    for (int i = 0; i < q; ++i) {
        int ord;
        cin >> ord;

        if (ord == 1) {
            int i, j, k;
            cin >> i >> j >> k;

            loc_map[{i, j}] = k;

        } else if (ord == 2) {
            int i, j;
            cin >> i >> j;
            cout << loc_map[{i, j}] << endl;
        }
    }
}