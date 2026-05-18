def summation(a, b):
    return (a + b) % MOD

def product(a, b):
    return (a * b) % MOD


n, k = map(int, input().split())

MOD = 998244353

ls = list(map(int, input().split()))

op = input()

power = 0

for ch in op:
    if ch == 's':
        for x in range(0, n):
            
    elif ch == 'p':
        power = product(power, ls[0])
