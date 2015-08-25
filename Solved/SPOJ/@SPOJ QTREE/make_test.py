from random import randrange as rr

def get(lt): return lt[rr(len(lt))]

def generateQuery(m, k):
    for i in range(k):
        print "QUERY", rr(1, m+1), rr(1, m+1)

def generateChange(m, qt):
    for i in range(1, qt):
        print "CHANGE", rr(1, m), rr(1, 1000000)

def generateTest(m):
    ind = 2
    st = [1]
    for i in range(m):
        print get(st), ind, 1
        st.append(ind)        
        ind += 1

qtTests = 20
print qtTests
for i in range(qtTests):
    m = 10000
    print m
    generateTest(m)
    for k in range(100):
        generateChange(m, 1000)        
        generateQuery(m, 1000)
    print "DONE"
