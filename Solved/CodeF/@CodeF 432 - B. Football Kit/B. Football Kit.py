import sys

MAX = 100010

r = raw_input().split(" ")
n = int(r[0])
teams = [[0,0] for i in range(n)]
qt_home = [0 for i in range(MAX)]
qt_away = [0 for i in range(MAX)]
for i in range(n):
    r = raw_input().split(" ")
    h = int(r[0]); a = int(r[1])
    teams[i][0] = h; teams[i][1] = a
    qt_home[h] += 1; qt_away[a] += 1

for i in range(n):
    h = teams[i][0]; a = teams[i][1]
    my_home = n - 1 + qt_home[a]
    my_away = n - 1 - qt_home[a]
    print my_home , my_away
