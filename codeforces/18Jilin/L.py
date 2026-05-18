MOD = 998244353

T = int(input());
for _ in range(T):
    n, m = map(int, input().split())

    matrix = [[0] * m for _ in range(n)]
    