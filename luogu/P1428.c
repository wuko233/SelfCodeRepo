#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int kawaii[n];

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &kawaii[j]);
        }
    }

    for (int j = 0; j < n; j++) {
        int cnt = 0;
        for (int k = 0; k < j; k++) {
            if (kawaii[k] < kawaii[j]) {
                cnt++;
            }
        }
        printf("%d ", cnt);
    }


}