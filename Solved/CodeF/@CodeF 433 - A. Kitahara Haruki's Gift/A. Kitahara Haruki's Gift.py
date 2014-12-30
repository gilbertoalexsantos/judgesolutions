import sys

r = raw_input().split(" ")
n = int(r[0])
r = raw_input().split(" ")
q1 = 0; q2 = 0;
for i in r:
    if i == "100":
        q1 += 1
    else:
        q2 += 1

def calc(q1, q2):
    for i in range(q1+1):
        for j in range(q2+1):
            p1 = i * 100 + j * 200
            p2 = (q1 - i) * 100 + (q2 - j) * 200
            if p1 == p2:
                return True
    return False

if q1 == 0:
    if q2 % 2 == 0:
        print "YES"
    else:
        print "NO"
elif q2 == 0:
    if q1 % 2 == 0:
        print "YES"
    else:
        print "NO"
elif calc(q1,q2):
    print "YES"
else:
    print "NO"
