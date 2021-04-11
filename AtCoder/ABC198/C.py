import math


r, x, y = [int(x) for x in input().strip().split()]

# ans**2 * r**2 >= x**2 + y**2
ans = int(math.sqrt((x**2 + y**2) // r**2))
while ans**2 * r**2 < x**2 + y**2:
    ans += 1

if ans == 1 and r**2 != x**2 + y**2:
    ans += 1

print(ans)
