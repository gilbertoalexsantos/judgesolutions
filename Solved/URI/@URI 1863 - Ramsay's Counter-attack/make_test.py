from random import randrange as rr

n = 15
m = 7
print n, m


al = {}
for i in range(n):
    u = rr(20)
    v = rr(20)
    if (u, v) in al: continue
    al[(u, v)] = True
    print u, v

already = {}
edge = [False for i in range(n+1)]
for j in range(m):
    u = rr(1, n+1)
    v = rr(1, m+1)
    while (u, v) in already  or (v, u) in already or u == v or edge[u]:
        u = rr(1, n+1)
        v = rr(1, n+1)
    edge[u] = True
    already[(u, v)] = True
    print u, v
    
