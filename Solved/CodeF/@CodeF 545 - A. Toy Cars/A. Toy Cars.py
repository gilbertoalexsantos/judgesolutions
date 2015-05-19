//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/545/problem/A

n = int(raw_input())

m = []
for i in range(n):
    m.append(map(int, raw_input().split(" ")))

ans = []
for r in range(n):
    row = m[r]
    ok = True
    for c in row:
        if c == 3 or c == 1:
            ok = False
            break
        pass

    if ok: ans.append(r)

print len(ans)
for i in range(len(ans)):
    print ans[i] + 1,
