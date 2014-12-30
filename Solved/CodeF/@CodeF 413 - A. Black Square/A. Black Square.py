import sys

cal = raw_input().split(" ")
r = raw_input()

ans = 0
for i in r:
    ans += int(cal[int(i) - 1])
print ans
