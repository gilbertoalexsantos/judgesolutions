# Author:   Gilberto A. dos Santos
# Website:  http://codeforces.com/problemset/problem/402/B

import sys

r = raw_input().split(" ")
n = int(r[0])
k = int(r[1])
arr = [0 for i in range(n)]
ans = [0 for i in range(n+1)]
r = raw_input().split(" ")
for i in range(n):
    arr[i] = int(r[i])

def bruteforce(): 
    global ans
    flag = []
    for constant in range(1,1001):
        flag = []
        # (C + 0K) (C + 1K) (C + 2k) (C + 3k) (C + 4k)  (C + 5k)
        for i in range(n):
            new_value = (k * i) + constant
            diff = arr[i] - new_value
            if diff:
                flag.append(["+" if diff < 0 else "-",i+1,abs(diff)])
        if len(ans) > len(flag):
            ans = flag

bruteforce()
print len(ans)
for i in ans:
    print i[0],i[1],i[2]
