#include <stdio.h>

int main() {
    int unhappyday = 0;
    int maxUnhappyPoint = 0;
    for (int i = 0; i < 7; i++) {
        int unhappyPoint = 0;
        int schoolTime, otherTime;
        scanf("%d %d", &schoolTime, &otherTime);
        unhappyPoint = schoolTime + otherTime - 8;
        if (unhappyPoint > maxUnhappyPoint) {
            maxUnhappyPoint = unhappyPoint;
            unhappyday = i + 1;
        }
    }

    printf("%d\n", unhappyday);
}