mod = 998244353

n = int(input())

# a + b + c + d + e + f = n
# ans = C(n-1, 5)
a = (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) // 120

# a + b + 4c = n
b = (n - 5 + n - 4 * ((n - 2) // 4) - 1) * ((n - 2) // 4) // 2

# a + b + 2c + 2d = n
um = (n - 2) // 2
c = -2 * um * (um + 1) * (um * 2 + 1) // 6 + (n + 1) * um * (um + 1) // 2 - (n - 1) * um

# 2a + 2b + 2c = n
# ans = C(n/2-1, 2)
d = 0
if n % 2 == 0:
    d = (n // 2 - 1) * (n // 2 - 2) // 2

# 3a + 3b = n
# ans = n/3-1
e = 0
if n % 3 == 0:
    e = n // 3 - 1

ans = (a + b * 6 + c * 3 + d * 6 + e * 8) // 24
ans %= mod
print(ans)
