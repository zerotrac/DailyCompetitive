n = input().strip()

cnt = 0
for ch in n:
    if ch == "0":
        cnt += 1
    else:
        cnt = 0

n = "0" * cnt + n
print("Yes" if n == n[::-1] else "No")
