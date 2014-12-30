from random import randrange as rr
from sys import stdout

wr = stdout.write

GRID_ROW = 2
GRID_COL = 2

print GRID_ROW, GRID_COL
for i in range(GRID_ROW):
    for j in range(GRID_COL):
        wr(str(rr(10000)) + " " )
    print

QT_ASK = 1
print QT_ASK
li = []
for i in range(QT_ASK):
    x = rr(1,GRID_ROW)
    y = rr(1,GRID_COL)
    while len(li) != 0 and x == li[i-1][0] and y == li[i-1][1]:
        x = rr(1,GRID_ROW)
        y = rr(1,GRID_COL)
    li.append([x,y])
    print x, y
