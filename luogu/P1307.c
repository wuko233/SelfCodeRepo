#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    int isNegative = 0;
    if (n < 0) {
        isNegative = 1;
        n = -n;
    }

    int numbers[10];
    int index = 0;
    while (n > 0) {
        numbers[index++] = n % 10;
        n /= 10;
    }

    if (isNegative) {
        printf("-");
    }

    int start = 0;
    for (int i = 0; i < index; i++) {
        if (numbers[i] != 0) {
            start = i;
            break;
        }
    }
    
    
    for (int i = start; i < index; i++) {
        printf("%d", numbers[i]);
        
    }


}