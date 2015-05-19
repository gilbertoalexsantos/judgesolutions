//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/545/problem/B

a1 = raw_input()
a2 = raw_input()

diff = 0
for i in range(len(a1)):
    if a1[i] != a2[i]:
        diff += 1
        pass
    pass

if diff % 2 != 0:
    print "impossible"
    exit()

cnt1 = 0
cnt2 = 0

ans = []

for i in range(len(a1)):
    c1 = a1[i]
    c2 = a2[i]
    if c1 == c2:
        ans.append(c1)
        continue
    if cnt1 > cnt2:
        ans.append(c1)
        cnt2 += 1
    else:
        ans.append(c2)
        cnt1 += 1

print ''.join(ans)
