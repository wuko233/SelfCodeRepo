#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int SCR[] = {0, 2000, 1000, 200, 36, 6};

int main() {

    // 竞赛常用的输入输出优化
    ios::sync_with_stdio(false); // 关闭C++和C的输入输出同步，加快速度
    cin.tie(nullptr); // 解除cin和cout的绑定，进一步提高速度

    int n, k, quality;
    string name;

    cin >> n >> k;

    unordered_map<string, int> itemQuality; // 哈希表存储物品及其品质
    // 类似 Java 中的 HashMap, python 中的 dict

    unordered_set<string> obtainedItems; // 哈希集合存储已获取的物品

    for (int i = 0; i < n; i++) {
        cin >> name >> quality;
        itemQuality[name] = quality;
    }

    int total = 0;

    for (int i = 0; i < k; i++) {
        cin >> name;

        if (obtainedItems.count(name)) {
            total += SCR[itemQuality[name]];
        } else {
            obtainedItems.insert(name);
        }
    }

    cout << total << endl;

    return 0;
}