T = int(input())

def work():
    hmax, mmax = [int(x) for x in input().strip().split()]
    t = input().strip()
    h, m = [int(x) for x in t.split(":")]

    swp = {
        "0": "0",
        "1": "1",
        "2": "5",
        "5": "2",
        "8": "8",
        ":": ":",
    }

    def good(h, m):
        cur = f"{h:02d}:{m:02d}"
        if any(c in cur for c in "34679"):
            return False
        ref = "".join(swp[c] for c in cur)
        hh, mm = [int(x) for x in ref[::-1].split(":")]
        return 0 <= hh < hmax and 0 <= mm < mmax

    while not good(h, m):
        m += 1
        if m == mmax:
            h += 1
            m = 0
            if h == hmax:
                h = 0
    
    print(f"{h:02d}:{m:02d}")


for _ in range(T):
    work()