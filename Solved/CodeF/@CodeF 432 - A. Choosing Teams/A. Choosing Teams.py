import sys

r = raw_input().split(" ")
n = int(r[0]); k = int(r[1])
arr = [0 for i in range(n)]
r = raw_input().split(" ")
for i in range(n):
    arr[i] = int(r[i]) + k
arr.sort()

def ver(pos):
    if pos + 2 >= n:
        return 0
    if arr[pos] <= 5 and arr[pos+1] <= 5 and arr[pos+2] <= 5:
        return 1
    else:
        return 0

ret = 0
i = 0
while i < n:
    ret += ver(i)
    i += 3
print ret
