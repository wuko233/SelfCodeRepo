#include <stdio.h>

int giveTurtle(int n) {
    if (n <= 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return giveTurtle(n - 1) * n;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", giveTurtle(n));

}