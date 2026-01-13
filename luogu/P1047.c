#include <stdio.h>

int main() {
    int l, m;
    scanf("%d %d", &l, &m);
    int isRemoveed[l+1];
    for (int i = 0; i <= l; i++) {
        isRemoveed[i] = 0;
    }

    for (int i = 0; i < m; i++) {

        int u, v;
        scanf("%d %d", &u, &v);

        for (int j = u; j <= v; j++) {
            isRemoveed[j] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= l; i++) {
        if (isRemoveed[i] == 0) {
            cnt++;
        }
    }

    printf("%d", cnt);
}