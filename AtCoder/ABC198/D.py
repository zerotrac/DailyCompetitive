from collections import Counter

s1 = input().strip()
s2 = input().strip()
s3 = input().strip()

c = Counter()
banned = set()

def init(s: str, op: int):
    base = 1
    for ch in s[::-1]:
        c[ch] += base * op
        op *= 10
    banned.add(s[0])

init(s1, +1)
init(s2, +1)
init(s3, -1)

d = list(c.items())
d.sort(key=lambda x: -abs(x[1]))
# print(d)

bound = [(0, 0)] * (len(d) + 1)
for i in range(len(d) - 1, -1, -1):
    if d[i][1] > 0:
        bound[i] = (bound[i + 1][0] - d[i][1] * 9, bound[i + 1][1])
    else:
        bound[i] = (bound[i + 1][0], bound[i + 1][1] - d[i][1] * 9)

rest = set(range(10))
rep = dict()
found = False

def dfs(pos: int, total: int):
    if pos == len(d):
        global found
        found = True
        return
    
    r = rest.copy()
    for num in r:
        if num == 0 and d[pos][0] in banned:
            continue
        nxttotal = total + d[pos][1] * num
        if bound[pos + 1][0] <= nxttotal and nxttotal <= bound[pos + 1][1]:
            rest.discard(num)
            rep[d[pos][0]] = num
            dfs(pos + 1, nxttotal)
            rest.add(num)
        if found:
            break

dfs(0, 0)

def prints(s: str):
    dum = "".join(str(rep[ch]) for ch in s)
    print(dum)

if not found:
    print("UNSOLVABLE")
else:
    prints(s1)
    prints(s2)
    prints(s3)