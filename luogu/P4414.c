#include <stdio.h>

int main() {
    int n1, n2, n3;
    scanf("%d %d %d\n", &n1, &n2, &n3);

    int list[3] = {n1, n2, n3};
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    

    char c1, c2, c3;
    scanf("%c%c%c", &c1, &c2, &c3);
    char order[3] = {c1, c2, c3};
    for (int i = 0; i < 3; i++) {
        if (order[i] == 'A') {
            printf("%d ", list[0]);
        } else if (order[i] == 'B') {
            printf("%d ", list[1]);
        } else if (order[i] == 'C') {
            printf("%d ", list[2]);
        }
    }
}