n, k, x = map(int,raw_input().split(" "))

r = map(int,raw_input().split(" "))
tuples = []
i = 0
while i < n:
    t = r[i]; qt = 0
    while i < n and r[i] == t:
        qt += 1; i += 1;
    tuples.append([t,qt])

init_value = sum(tuples[i][1] for i in range(len(tuples)))

def combine(tuples):
    i = 0
    while i < len(tuples) - 1:
        if tuples[i][0] == tuples[i+1][0]:
            tuples[i+1][1] += tuples[i][1]
            tuples.pop(i)
        else:
            i += 1

def poke(tuples):
    ret = False
    i = 0
    while i < len(tuples):
        if tuples[i][1] >= 3:
            tuples.pop(i)
            ret = True
        else:
            i += 1
    return ret

def cnt(pos):
    temp = [[tuples[i][0],tuples[i][1]] for i in range(len(tuples))]
    temp[pos][1] = 3
    while poke(temp):
        combine(temp)
    end_value = sum(temp[i][1] for i in range(len(temp)))
    return init_value - end_value

ans = 0
for i in range(len(tuples)):
    if tuples[i][0] == x and tuples[i][1] == 2:
        ans = max(ans,cnt(i))
print ans
