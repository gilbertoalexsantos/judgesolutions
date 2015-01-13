#Author: Gilberto A. dos Santos
#Website: http://codeforces.com/contest/501/problem/A

def getTime(points, time):
    p1 = (3 * points) / 10
    p2 = points - (points / 250) * time
    return max(p1, p2)

a, b, c, d = map(int, raw_input("").split(" "))

misha = getTime(a, c)
vasya = getTime(b, d)

if misha == vasya: print "Tie"
elif misha > vasya: print "Misha"
else: print "Vasya"
