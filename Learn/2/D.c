#include <stdio.h>
#include <stdlib.h>

struct Machine {
    int id;
    int x;
    int y;
};

int main() {
    int n, k, T;
    scanf("%d %d %d", &n, &k, &T);
    
    // 密码机坐标
    struct Machine* crypto_machine = (struct Machine*)malloc(sizeof(struct Machine) * n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        crypto_machine[i].id = i;
        crypto_machine[i].x = x;
        crypto_machine[i].y = y;
    }

    // 求生者选定的坐标，出生密码机
    struct Machine* survivor = (struct Machine*)malloc(sizeof(struct Machine) * k);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        survivor[i].x = x;
        survivor[i].y = y;
        for (int j = 0; j < n; j++) {
            if (crypto_machine[j].x == x && crypto_machine[j].y == y) {
                survivor[i].id = j;
                break;
            }
        }
    }

    int answer = 0;

    // 监管者
    for (int i = 0; i < T; i++) {
        int mx, my;
        scanf("%d %d", &mx, &my);

        int max_distance = -1;
        int banned_id = -1;

        for (int j = 0; j < n; j++) {
            int distance = (crypto_machine[j].x - mx) * (crypto_machine[j].x - mx) +
                           (crypto_machine[j].y - my) * (crypto_machine[j].y - my);
            if (distance > max_distance) { 
                max_distance = distance;
                banned_id = crypto_machine[j].id;
            } else if (distance == max_distance) {
                if (crypto_machine[j].id < banned_id) {
                    banned_id = crypto_machine[j].id;
                }
            }
        }

        for (int j = 0; j < k; j++) {
            if (survivor[j].id == banned_id) {
                answer++;
                break;
            }
        }

    }

    printf("%d\n", answer);
    free(crypto_machine);
    free(survivor);

    return 0;

}