import sys

m = [[0 for i in range(5)] for i in range(5)]
visited = [False for i in range(5)]
l = []
for i in range(5):
    r = raw_input().split(" ")
    for j in range(5):
        m[i][j] = int(r[j])

def val():
    qt = 0
    for i in range(4):
        for j in range(i,5,2):
            if j == 4: continue
            qt += m[l[j]][l[j+1]] + m[l[j+1]][l[j]]
    return qt

def perm(n=0):
    ans = -1
    if n == 5:
        return val()
    else:
        for i in range(5):
            if visited[i]: continue
            visited[i] = True
            l.append(i)
            ans = max(ans,perm(n + 1))
            l.pop()
            visited[i] = False
    return ans

print perm()
