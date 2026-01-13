#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);
    
    int coins = 0;
    int maxPeriod = 0;
    for (int i = 1;; i++) {
        if (i * (i + 1) / 2 > k) {
            maxPeriod = i - 1;
            break;
        }
    }
    int passDays = 0;
    for (int i = 1; i <= maxPeriod; i++) {
        coins += i * i;
        passDays += i;
    }

    int remainDays = k - passDays;
    coins += remainDays * (maxPeriod + 1);

    printf("%d", coins);
}