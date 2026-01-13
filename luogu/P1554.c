#include <stdio.h>

void countNumber(int number, int count[]) {
    while (number > 0) {
        int div = number % 10;
        count[div]++;
        number /= 10;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int count[10] = {0};
    for (int i = m; i <= n; i++) {
        countNumber(i, count);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", count[i]);
    }
}