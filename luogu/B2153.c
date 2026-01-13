#include <stdio.h>

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1;i <= n;i++) {
        sum += factorial(i);
    }

    printf("%d", sum);

}