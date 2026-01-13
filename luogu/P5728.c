#include <stdio.h>
#include <stdlib.h>

#define MAX_DEEPTH 26

struct student {
    int chinese;
    int math;
    int english;
    int total;
};

struct bucket_node {
    int student_index;
    struct bucket_node* next;
};

int main() {

    int n;
    scanf("%d", &n);

    struct student* students = (struct student*)malloc(n * sizeof(struct student));

    struct bucket_node* buckets[MAX_DEEPTH][MAX_DEEPTH][MAX_DEEPTH] = {NULL};

    for (int i = 0; i < n; i++) {
        int c, m, e;
        scanf("%d %d %d", &c, &m, &e);
        students[i].chinese = c;
        students[i].math = m;
        students[i].english = e;
        students[i].total = c + m + e;

        int bC = c / 6;
        int bM = m / 6;
        int bE = e / 6;

        // 头插链表
        struct bucket_node* new_node = (struct bucket_node*)malloc(sizeof(struct bucket_node));
        new_node->student_index = i;
        new_node->next = buckets[bC][bM][bE];
        buckets[bC][bM][bE] = new_node;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int c = students[i].chinese;
        int m = students[i].math;
        int e = students[i].english;
        int t = students[i].total;

        int bC = c / 6;
        int bM = m / 6;
        int bE = e / 6;

        // 遍历偏移量offset，-1,0,1
        for (int oc = -1; oc <= 1; oc++) {
            int nbC = bC + oc; // nearBC
            if (nbC < 0 || nbC >= MAX_DEEPTH) continue;

            for (int om = -1; om <= 1; om++) {
                int nbM = bM + om; // nearBM
                if (nbM < 0 || nbM >= MAX_DEEPTH) continue;

                for (int oe = -1; oe <= 1; oe++) {
                    int nbE = bE + oe; // nearBE
                    if (nbE < 0 || nbE >= MAX_DEEPTH) continue;

                    struct bucket_node* current = buckets[nbC][nbM][nbE];

                    // 遍历链表
                    while(current != NULL) {

                        int index = current->student_index;

                        if (index > i) { // 无序对，只检查一次
                            int ic = students[index].chinese;
                            int im = students[index].math;
                            int ie = students[index].english;
                            int it = students[index].total;

                            // 某对学生 ⟨i,j⟩ 每一科成绩的分差都不大于 5，且总分分差不大于 10
                            if (abs(c - ic) <= 5 &&
                                abs(m - im) <= 5 &&
                                abs(e - ie) <= 5 &&
                                abs(t - it) <= 10) {
                                    cnt++;
                            }

                        }
                        current = current->next;
                    }
                }
            }
        }

    }

    printf("%d\n", cnt);

}