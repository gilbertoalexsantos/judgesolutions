n = int(raw_input())

beg = 1
cnt = 1
for i in range(n-1):
    th = (beg + cnt) % n
    if th == 0:
        print n,
    else:
        print th,
    beg = th
    cnt += 1
print
