#include <stdio.h>
#include <string.h>

struct Item {
    char name[11];
    int quantity;
    int obtained;
} Item;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    struct Item items[100];

    for (int i = 0; i < n; i++) {
        char name[11];
        int quality;
        scanf("%s %d", name, &quality);
        strcpy(items[i].name, name);
        items[i].quantity = quality;
        items[i].obtained = 0;
    }

    int total = 0;

    for (int i = 0; i < k; i++) {
        char getItem[11];
        scanf("%s", getItem);

        for (int j = 0; j < n; j++) {
            if (strcmp(getItem, items[j].name) == 0) {
                if (items[j].obtained == 0) {
                    items[j].obtained = 1;
                } else {
                    switch (items[j].quantity) {
                        case 1:
                            total += 2000;
                            break;
                        case 2:
                            total += 1000;
                            break;
                        case 3:
                            total += 200;
                            break;
                        case 4:
                            total += 36;
                            break;
                        case 5:
                            total += 6;
                            break;
                    }
                }
                break;
            }
        }
    }

    printf("%d\n", total);
}