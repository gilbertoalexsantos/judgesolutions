n, m = map(int,raw_input().split(" "))

a = map(int,raw_input().split(" "))
b = map(int,raw_input().split(" "))

min_a = reduce(min,a)
max_b = reduce(max,b)

if min_a >= max_b:
    print 0
else:
    a.sort()
    b.sort()
    j = len(a) - 1
    for i in range(len(a)):
        if a[i] > b[len(b)-1]:
            j = i-1
            break
    nmax = a[j]
    ans = abs(a[j] - b[len(b)-1])
    for i in range(j):
        ans += a[j] - a[i]
    for i in range(len(b)-1):
        if b[i] > nmax:
            ans += b[i] - nmax
    print ans
