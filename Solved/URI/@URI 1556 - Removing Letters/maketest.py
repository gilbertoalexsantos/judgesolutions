from random import randrange
from sys import stdout

w = "abcdefghijklmnopqrstuvwxyz"

QT = randrange(1,10)
for j in range(QT):
    for i in range(7):
        stdout.write(w[randrange(len(w))])
    print
