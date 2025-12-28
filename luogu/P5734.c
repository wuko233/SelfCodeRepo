#include <stdio.h>
#include <string.h>

void insertAndPrint(char* str, char* substr, int pos) {
    char temp[201];

    if (pos == -1) {
        pos = strlen(str);
    }

    int i = 0;
    for (; i < pos; i++) {
        temp[i] = str[i];
    }

    int j = 0;
    for (; substr[j] != '\0'; j++, i++) {
        temp[i] = substr[j];
    }

    for (int k = pos; str[k] != '\0'; k++, i++) {
        temp[i] = str[k];
    }

    temp[i] = '\0';
    strcpy(str, temp);
    printf("%s\n", str);
}

void splitAndPrint(char* str, int start, int end) {
    char temp[201];
    int i = 0;
    for (int k = start; k < end; k++, i++) {
        temp[i] = str[k];
    }
    temp[i] = '\0';
    strcpy(str, temp);
    printf("%s\n", str);
}

void findAndPrintPos(char* str, char* substr) {
    int i = 0;
    for (; str[i] != '\0'; i++) {
        int j = 0;
        for (; substr[j] != '\0'; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (substr[j] == '\0') {
            printf("%d\n", i);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    int q;
    scanf("%d", &q);

    char str[201];
    scanf("%s", str);

    for (int i = 0; i < q; i++) {
        int control;
        scanf("%d", &control);
        switch (control) {
            case 1: {
                char substr[101];
                scanf("%s", substr);
                insertAndPrint(str, substr, -1);
                break;
            }
            case 2: {
                int start = 0, end = 0;
                scanf("%d %d", &start, &end);
                end += start;
                splitAndPrint(str, start, end);
                break;
            }
            case 3: {
                char substr1[101];
                int pos = 0;
                scanf("%d", &pos);
                scanf("%s", substr1);
                
                insertAndPrint(str, substr1, pos);
                break;
            }
            case 4: {
                char substr2[101];
                scanf("%s", substr2);
                findAndPrintPos(str, substr2);
                break;
            }
            default:
                break;
        }
    }

}