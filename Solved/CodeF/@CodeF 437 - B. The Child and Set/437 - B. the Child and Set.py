s, l = map(int,raw_input().split(" "))

ans = []
for i in range(l,0,-1):
    last_bit = i & -i
    s -= last_bit
    if s < 0: 
        s += last_bit
    else:
        ans.append(i)
    if s == 0: break

if s == 0:
    print len(ans)
    for i in ans:
        print i,
    print
else:
    print -1
