#include <stdio.h>

int isPrime(int num) {
    if (num == 1) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int list[n];

    for (int i =0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < n; i++) {
        if (isPrime(list[i])) {
            printf("%d ", list[i]);
        }
    }
}