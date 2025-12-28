#include <stdio.h>

int calc(int n, int x) {
    int cnt = 0;
    while (n > 0) {
        if (n % 10 == x) {
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}

int main() {
    int n, x, cnt = 0;
    scanf("%d %d", &n, &x);

    for (int i = 1; i <= n; i++) {
        cnt += calc(i, x);
    }

    printf("%d\n", cnt);
}