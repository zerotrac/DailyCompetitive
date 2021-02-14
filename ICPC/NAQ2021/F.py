n = int(input())
for i in range(n):
    st = input()
    if st.startswith("Simon says"):
        print(st[10:])
