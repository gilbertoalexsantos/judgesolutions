//Author: Gilberto A. dos Santos
//Website: http://codeforces.com/contest/545/problem/C

n = int(raw_input())

trees = []

for i in range(n):
    x, y = map(int, raw_input().split(" "))
    trees.append([x, y])

if n == 1:
    print 1
    exit()

ans = 2
left = trees[0][0]
for i in range(1, n-1):
    x, h = trees[i]
    toLeft = x - h
    toRight = x + h
    if toLeft > left:
        left = x
        ans += 1
    else:
        xn, hx = trees[i+1]
        toLeftn = xn - hx
        if toRight >= xn:
            left = x
            continue
        else:
            left = toRight
            ans += 1

print ans
