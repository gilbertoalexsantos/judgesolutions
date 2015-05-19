//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/545/problem/D

from random import randrange as rr

n = int(raw_input())

a = map(int, raw_input().split(" "))

a.sort()

sum = a[0]
ans = 1
for i in range(1, n):
    if sum <= a[i]:
        ans += 1
        sum += a[i]

print ans
