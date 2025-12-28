#include <stdio.h>

int main() {
    int s1, s2, s3;
    scanf("%d %d %d", &s1, &s2, &s3);

    int frequency[101] = {0};

    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                frequency[i+j+k]++;
            }
        }
    }

    int maxFreq = 0;
    int result = 0;

    int maxSum = s1 + s2 + s3;
    for (int i = 3; i <= maxSum; i++) {
        if (frequency[i] > maxFreq) {
            maxFreq = frequency[i];
            result = i;
        }
    }
    printf("%d\n", result);
    
}