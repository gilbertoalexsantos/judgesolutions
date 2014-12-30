from random import randrange as rr
from sys import stdout

wr = stdout.write

SIZE_GRID = rr(25,26)

def get(): return [rr(SIZE_GRID),rr(SIZE_GRID)]

for j in range(1):
    QT_DOOR = rr(5,6)
    QT_WALL = rr(200,201)

    gg = []

    def has(q):
        for ele in gg:
            if q[0] == ele[0] and q[1] == ele[1]: return True
        return False

    source = get()
    gg.append(source)

    sink = get()
    while has(sink): sink = get()
    gg.append(sink)

    block = get()
    while has(block): block = get()
    gg.append(block)

    door = []
    for i in range(QT_DOOR):
        d = get()
        while has(d): d = get()
        door.append(d)
        gg.append(d)
    wall = []
    for i in range(QT_WALL):
        d = get()
        while has(d): d = get()
        wall.append(d)
        gg.append(d)

    def has_wall(d):
        for i in wall:
            if d[0] == i[0] and d[1] == i[1]: return True
        return False

    def has_door(d):
        for i in door:
            if d[0] == i[0] and d[1] == i[1]: return True
        return False

    print SIZE_GRID, SIZE_GRID
    for i in range(SIZE_GRID):
        for j in range(SIZE_GRID):
            if i == source[0] and j == source[1]:
                wr('j')
            elif i == sink[0] and j == sink[1]:
                wr('x')
            elif i == block[0] and j == block[1]:
                wr('b')
            elif has_wall([i,j]):
                wr('*')
            elif has_door([i,j]):
                wr('#')
            else:
                wr('.')
        wr("\n")
