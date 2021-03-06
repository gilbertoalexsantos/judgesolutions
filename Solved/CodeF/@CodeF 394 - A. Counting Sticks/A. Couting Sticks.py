# Author:   Gilberto A. dos Santos
# Website:  http://codeforces.com/problemset/problem/394/A

import sys

data = sys.stdin.readline().rstrip()

plus = data.find("+")
equal = data.find("=")
a = len(data[:plus])
b = equal - plus - 1
c = len(data[equal+1:])

def solve(a, b, c):
    for i in range(3): 
        for j in range(3):
            l = [a,b,c]
            l[i] = l[i]+1
            l[j] = l[j]-1
            if(l[j] == 0): continue
            if l[0]+l[1] == l[2]: return l
    return [-1,-1,-1]

r = abs((a+b)-c)
if(r == 0 or r == 2):
    ans = solve(a,b,c)
    output = ("|"*ans[0]) + "+" + ("|"*ans[1]) + "=" + ("|"*ans[2])
    print output
else:
    print "Impossible"
