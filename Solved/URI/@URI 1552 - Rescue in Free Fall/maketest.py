from random import randrange as rr

m = [[False for i in range(105)] for j in range(105)]

QT_TEST = rr(4,5)

print 1
print QT_TEST
for i in range(QT_TEST):
    a = rr(0,100)
    b = rr(0,100)
    while m[a][b]:
        a = rr(0,100)
        b = rr(0,100)
    print a, b
    m[a][b] = True
