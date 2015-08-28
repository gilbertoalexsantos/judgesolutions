from random import randrange as rr

qt = 3
for i in range(qt):
    q = 100000
    print q
    for j in range(q):
        if rr(100) % 7 == 0:
            print "SET", rr(-500, 501), rr(-500, 501), rr(1000000)
        else:
            print "QUERY", rr(-500, 501), rr(-500, 501), rr(1)
