a = [int(x) for x in input().strip().split()]

ans = set()

# stage = 0: combine
# stage = 1: times
# stage = 2: plus or minus

def rmv(b, i, j, elem):
    return [x for k, x in enumerate(b) if k != i and k != j] + [elem]

def dfs(b, stage):
    if len(b) == 1:
        if stage != 0 and b[0] >= 0:
            ans.add(b[0])
        return
    
    l = len(b)

    if stage == 0:
        dfs(b, 1)
    
    if stage == 1:
        dfs(b, 2)
    
    for i in range(l):
        for j in range(l):
            if i != j:
                if stage == 0:
                    elem = int(str(b[i]) + str(b[j]))
                elif stage == 1:
                    elem = b[i] * b[j]
                else:
                    elem = b[i] + b[j]

                bb = rmv(b, i, j, elem)
                dfs(bb, stage)

                if stage == 2:
                    elem = b[i] - b[j]
                    bb = rmv(b, i, j, elem)
                    dfs(bb, stage)

dfs(a, 0)
print(len(ans))
