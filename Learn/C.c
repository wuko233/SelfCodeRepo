#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int n, x0;
    scanf("%lld %lld", &n, &x0);

    int* needSpirit = (int*)malloc(n * sizeof(int));
    int* addSpirit = (int*)malloc(n * sizeof(int));

    for (long long int i = 0; i < n; i++) {
        long long int need;
        scanf("%d", &need);
        needSpirit[i] = need;
    }

    for (long long int i = 0; i < n; i++) {
        long long int add;
        scanf("%lld", &add);
        addSpirit[i] = add;
    }

    // 开始模拟
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
        if (x0 >= needSpirit[i]) {
            x0 += addSpirit[i];
            cnt++;
        }
    }

    printf("%lld\n", cnt);
}