#include <stdio.h>

int main() {
    long long int y0, t;
    scanf("%lld %lld", &y0, &t);
    
    if (t == 0) {
        printf("NO\n"); 
        printf("YES\n"); 
        return 0;
    }
    
    if (y0 < 0 && t % 2 == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    if (y0 % 2 != 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}