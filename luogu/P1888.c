#include <stdio.h>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int e[3];
    scanf("%d %d %d", &e[0], &e[1], &e[2]);

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (e[i] < e[j]) {
                int temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    int gcdValue = gcd(e[0], e[2]);
    printf("%d/%d", e[2] / gcdValue, e[0] / gcdValue);


}