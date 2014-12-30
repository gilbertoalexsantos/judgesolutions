from random import randrange as rr

QT_CASE = 1
QT_SEA = 5
QT_D = 4

for i in range(QT_CASE):
    print QT_SEA, QT_D
    for j in range(QT_SEA):
        print rr(-5,5), rr(5)
print 0, 0
