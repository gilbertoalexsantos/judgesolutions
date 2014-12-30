from sys import stdout
from random import randrange

QT_TEST = 1

for i in range(QT_TEST):
    stdout.write(str(randrange(1,2)))
    st = ""
    for j in range(5000):
        st += (str(randrange(9)))
    print st
print 0
