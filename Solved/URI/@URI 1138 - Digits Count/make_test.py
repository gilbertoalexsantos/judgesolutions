from random import randrange as rr

QT_TEST = rr(100)
LIMIT = 1000

for i in range(QT_TEST):
    A = rr(1,LIMIT)

    B = rr(1,LIMIT)
    while B < A:
        B = rr(1,LIMIT)

    print A, B
print 0, 0
