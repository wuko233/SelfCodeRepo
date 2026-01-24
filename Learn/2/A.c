#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);
    if (k > 2) {
        printf("Survivor");
    } else if (k == 2) {
        printf("Tie");
    } else {
        printf("Hunter");
    }
}