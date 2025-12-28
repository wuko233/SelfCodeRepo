#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int out = 0;
    int cnt = 0;
    int m;

    while (scanf("%d", &m) == 1) {
        for (int j = 0; j < m; j++) {
            if (cnt == n) {
                printf("\n");
                cnt = 0;
            }
            printf("%d", out);
            cnt++;
        }
        if (out == 0) {
            out = 1;
        } else {
            out = 0;
        }
    }
}