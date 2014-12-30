# Author:   Gilberto A. dos Santos
# Website:  http://codeforces.com/problemset/problem/415/A

import sys

r = raw_input().split(" ")
n = int(r[0])
m = int(r[1])
light = [False for i in range(n)]

r = raw_input().split(" ")
for i in range(m):
    b = int(r[i])-1
    for j in range(b,n):
        if not(light[j]):
            light[j] = b+1

for i in range(n): print light[i],
