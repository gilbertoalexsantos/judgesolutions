from random import randrange as rr

qt = rr(1, 5)
for i in range(qt):
    m = rr(50, 51)
    print(m)
    for j in range(m):
        a = {}
        for z in range(3):
            x = rr(1, 10)
            while x in a: x = rr(1, 10)
            a[x] = 1
            print x,
        print
print 0
