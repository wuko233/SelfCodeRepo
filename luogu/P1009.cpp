#include <iostream>
#include <vector>

using namespace std;

// long long factor(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     return n * factor(n - 1);
// }


// 特大数高精度乘法
vector<int> multiply(vector<int> a, int b) {
    vector<int> result;
    int carry = 0; // 进位

    for (int i = 0; i < a.size(); i++) {
        carry += a[i] * b;
        result.push_back(carry % 10); // 当前位
        carry /= 10; // 更新进位
    }

    while (carry) {
        result.push_back(carry % 10);
        carry /= 10;
    }

    return result;
}

// 高精度加法
vector<int> add(vector<int> a, vector<int> b) {
    vector<int> result;
    int carry = 0; // 进位

    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];

        result.push_back(carry % 10); // 当前位
        carry /= 10; // 更新进位
    }

    if (carry) {
        result.push_back(carry);
    }

    return result;
}



int main() {
    int n;
    cin >> n;
    

    vector<int> factorial = {1};
    vector<int> sum = {0};

    for (int i = 1; i <= n; i++) {
        factorial = multiply(factorial, i);
        sum = add(sum, factorial);
    }

    for (int i = sum.size() - 1; i >= 0; i--) {
        cout << sum[i];
    }
    cout << endl;
    return 0;
}