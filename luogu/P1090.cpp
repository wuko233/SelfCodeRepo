#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    std::cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;

        q.push(a);
    }

    long long cost = 0;
    while(q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        cost += a + b;
        q.push(a + b);
    }

    std::cout << cost << std::endl;
}