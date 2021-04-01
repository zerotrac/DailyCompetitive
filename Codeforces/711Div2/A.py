import math


t = int(input())

for _ in range(t):
    x = int(input())
    while True:
        y = sum(int(u) for u in str(x))
        if math.gcd(x, y) > 1:
            break
        x += 1
    print(x)