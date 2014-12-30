import sys

r = raw_input().split(" ")
qt_points = int(r[0])

arr_points = [[0,i] for i in range(qt_points)]
ans = [0 for i in range(qt_points)]

r = raw_input().split(" ")
for i in range(qt_points):
    arr_points[i][0] = int(r[i])

arr_points.sort()
for i in range(qt_points):
    ans[arr_points[i][1]] = i % 2

for i in range(qt_points):
    print ans[i] ,
print
