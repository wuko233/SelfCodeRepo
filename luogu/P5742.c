#include <stdio.h>

struct student {
    int id;
    int learnScore;
    int sportsScore;
    double totalScore;
};

int getSum(struct student s) {
    return s.learnScore + s.sportsScore;
}

int isExcellent(struct student s) {
    if (getSum(s) > 140 && s.learnScore * 7 + s.sportsScore * 3 >= 800) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    struct student students[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &students[i].id, &students[i].learnScore, &students[i].sportsScore);
        students[i].totalScore = students[i].learnScore * 0.7 + students[i].sportsScore * 0.3;
        
        if (isExcellent(students[i])) {
            printf("Excellent\n");
        } else {
            printf("Not excellent\n");
        }
    }
    
    return 0;
}