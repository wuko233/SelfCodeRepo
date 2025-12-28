#include <stdio.h>

struct student {
    char name[21];
    int age;
    int score;
};

void passAYear(struct student* stu) {
    stu->age += 1;
    stu->score *= 1.2;
    if (stu->score > 600) {
        stu->score = 600;
    }
}


int main() {
    int n;
    scanf("%d", &n);

    struct student stu[n];
    for (int i= 0; i < n; i++) {
        scanf("%s %d %d", stu[i].name, &stu[i].age, &stu[i].score);
        passAYear(&stu[i]);
        printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].score);
    }

}
