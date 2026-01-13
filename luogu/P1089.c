#include <stdio.h>

int main() {
    int wallet = 0;
    int save = 0;
    int debtMonth = 0;

    for (int i = 1; i <= 12; i++) {
        wallet += 300;
        int budget;
        scanf("%d", &budget);

        if (wallet < budget) {
            debtMonth = i;
            break;
        }

        wallet -= budget;

        int remain = wallet / 100;
        if (remain > 0) {
            save += remain * 100;
            wallet -= remain * 100;
        }

    }

    if (debtMonth == 0) {
        int money = wallet + save + save * 0.2;
        printf("%d", money);
    } else {
        printf("-%d", debtMonth);
    }
}