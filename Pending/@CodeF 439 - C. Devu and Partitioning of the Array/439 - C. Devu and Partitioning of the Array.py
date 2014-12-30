from sys import stdout

out = stdout.write

def is_even(x): return x % 2 == 0
def is_odd(x): return x % 2 != 0

n, k, p = map(int,raw_input().split(" "))

arr = map(int,raw_input().split(" "))
visited = [False for i in range(n)]
arr_prime = map(lambda x: x % 2 != 0,arr)
arr_even = []
arr_odd = []
ans_even = []
ans_odd = []
for i in arr:
    if is_even(i): arr_even.append(i)
    else: arr_odd.append(i)

qt_odd = len(filter(lambda x: x,arr_prime))
qt_even = len(filter(lambda x: not(x),arr_prime))

need_odd = k - p
need_even = p

def can_even():
    global need_odd, need_even, qt_odd, qt_even
    global ans_even, ans_odd
    if need_odd == 0:
        if qt_odd != 0:
            if qt_odd % 2 != 0: return False
            for i in range(0,qt_odd,2): ans_odd.append(2)
            need_even -= qt_odd / 2
    if need_even == 0: return True
    if qt_even >= need_even:
        for i in range(need_even-1):
            ans_even.append(1)
        ans_even.append(qt_even-(need_even-1))
        return True
    need_even -= qt_even
    for i in range(qt_even):
        ans_even.append(1)
    if qt_odd >= (need_even * 2):
        qt_odd -= need_even * 2
        for i in range(need_even): 
            ans_odd.append(2)
        return True
    else: return False

def can_odd():
    global need_odd, need_even, qt_odd, qt_even
    global ans_even, ans_odd
    if qt_odd < need_odd: return False
    if need_odd == 0: return True
    qt_odd -= (need_odd - 1)
    if qt_odd % 2 == 0: return False
    for i in range(need_odd - 1):
        ans_odd.append(1)
    ans_odd.append(qt_odd)
    return True

if can_even() and can_odd():
    print "YES"
    for i in range(len(ans_even)):
        print ans_even[i],
        for j in range(ans_even[i]):
            print arr_even[len(arr_even)-1],
            arr_even.pop()
        print
    for i in range(len(ans_odd)):
        print ans_odd[i],
        for j in range(ans_odd[i]):
            print arr_odd[len(arr_odd)-1],
            arr_odd.pop()
        print
else:
    print "NO"
