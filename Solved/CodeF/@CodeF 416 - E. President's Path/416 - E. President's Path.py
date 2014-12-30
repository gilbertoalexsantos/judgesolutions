# Author:	Gilberto A. dos Santos
# Website:	http://codeforces.com/problemset/problem/416/E

import sys

INF = int(1e9)

r = raw_input().split(" ")
n = int(r[0])
m = int(r[1])
dist = [[INF for j in range(n)] for i in range(n)]
edge = [[INF for j in range(n)] for i in range(n)]
path = [[0 for j in range(n)] for i in range(n)]
for i in range(n): dist[i][i] = 0

def floyd():
    global dist
    for k in range (n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j])

def computePath():
    for source in range(n):
        qt_sink = [0 for i in range(n)]
        for sink in range(n):
            if dist[source][sink] == INF: continue
            for k in range(n):
                if k == sink: continue
                if dist[source][sink] == dist[source][k] + edge[k][sink]:
                    qt_sink[sink] += 1

        for sink in range(n):
            if dist[source][sink] == INF: continue
            for k in range(n):
                if dist[source][sink] == dist[source][k] + dist[k][sink]:
                    path[source][sink] += qt_sink[k]

for i in range(m):
    r = raw_input().split(" ")
    x = int(r[0])-1
    y = int(r[1])-1
    w = int(r[2])
    dist[x][y] = dist[y][x] = edge[x][y] = edge[y][x] = w

floyd()
computePath()
for i in range(n):
    for j in range(i+1,n):
        print path[i][j],
