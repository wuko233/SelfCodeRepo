#include <stdio.h>

long int transform(char* str) {
    long int result = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            result *= str[i] - 'a' + 1;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            result *= str[i] - 'A' + 1;
        }
    }
    return result;
}

int main() {
    char name[7];
    scanf("%s", name);

    char teamName[7];
    scanf("%s", teamName);

    if (transform(name) % 47 == transform(teamName) % 47) {
        printf("GO\n");
    } else {
        printf("STAY\n");
    }


}