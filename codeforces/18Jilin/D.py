import math

T = int(input())
for _ in range(T):

    x, y = map(int, input().split())

    z = -1
    for i in range(x+1, y):
        if math.gcd(i, x) == 1 and math.gcd(i, y) == 1:
            z = i
            break

    print(z)