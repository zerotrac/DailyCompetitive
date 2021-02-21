n, k = [int(x) for x in input().strip().split()]

for i in range(k):
    ns = sorted(str(n))
    g1 = int("".join(ns))
    g2 = int("".join(ns[::-1]))
    n = g2 - g1

print(n)
