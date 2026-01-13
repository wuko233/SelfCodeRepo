#include <stdio.h>
#include <string.h>

int main() {
    char line[200];
    scanf("%s", &line);

    int n = strlen(line);

    int isOne = (line[0] == '1') ? 1 : 0;
    // int result[n * n] = {0};
    int result[40000] = {0};

    int index = 0;
    int status;
    // 处理第一行
    do {
        for (int i = 0; i < n; i++) {
            int ch = (int) line[i];
            if (ch != isOne) {
                isOne = ch;
                result[++index]++;
            } else {
                result[index]++;
            }
        }
        status = scanf("%s", &line);
    } while (status > 0);

    printf("%d ", n);
    for (int i = 0; i <= index; i++) {
        printf("%d ", result[i]);
    }
}