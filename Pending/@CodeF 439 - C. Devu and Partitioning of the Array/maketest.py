from random import randrange

QT_NUMBER = 100000
K = 100000
P = 100000

n = randrange(QT_NUMBER)
k = randrange(1,K)
p = randrange(1,P)
while p > k: p = randrange(1,P)
print n, k, p
for i in range(n):
    print randrange(1,1000000000),
print
