from random import randrange as rr
from sys import stdout

numbers = {}

for i in range(1,11):
    QT = 2 ** i
    for i in range(QT):
        n = rr(0,10000)
        while numbers.has_key(n): n = rr(0,10000)
        stdout.write(str(n) + " ")
    stdout.write("\n")

    qt = 1
    arr = []
    while qt < QT:
        for j in range(qt): arr.append(j+1)
        qt *= 2
    arr.reverse()
    for ele in arr:
        stdout.write(str(ele) + " ")
    stdout.write("\n")
print 0
