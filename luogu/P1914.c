#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    char origin[51];
    char note[30] = "abcdefghijklmnopqrstuvwxyz";
    scanf("%s", origin);

    for (int i = 0; origin[i] != '\0'; i++) {
        int index = (origin[i] - 'a' + n) % 26;
        if (index < 0) {
            index += 26;
        }
        origin[i] = note[index];
    }

    printf("%s\n", origin);

}