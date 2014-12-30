raw_input()
v = map(int,raw_input().split(" "))
d = {}
for ele in v:
    if ele in d: 
        d[ele] += 1
    else: 
        d[ele] = 1
if len(d) == 1:
    print 0, len(v)*(len(v)-1)/2
else:
    arr = []
    for key, value in d.iteritems(): arr.append([key,value])
    arr.sort()
    print arr[len(arr)-1][0]-arr[0][0], arr[len(arr)-1][1]*arr[0][1]
