#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int A_sum = 0;
    int B_sum = 0;

    int A_cnt = 0;
    int B_cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            A_sum += i;
            A_cnt++;
        } else {
            B_sum += i;
            B_cnt++;
        }
    }

    double A_avg = A_cnt == 0 ? 0.0 : static_cast<double>(A_sum) / A_cnt;
    double B_avg = B_cnt == 0 ? 0.0 : static_cast<double>(B_sum) / B_cnt;

    printf("%.1f %.1f\n", A_avg, B_avg);
}