n, k, p = map(int, raw_input().split(" "))
arr = map(int, raw_input().split(" "))

qtNeedEven = p
qtNeedOdd = k - p

evens = filter(lambda x: x % 2 == 0, arr)
odds = filter(lambda x: x % 2 != 0, arr)

arrEven = []
arrOdd = []

if qtNeedEven == 0:
    if len(odds) >= qtNeedOdd and (len(odds) - qtNeedOdd) % 2 == 0:
        tempNeedOdd = qtNeedOdd
        while tempNeedOdd > 1:
            arrOdd.append([1, [odds.pop()]])
            tempNeedOdd -= 1
        arrOdd.append([len(odds) + len(evens), []])
        for ele in odds: arrOdd[len(arrOdd) - 1][1].append(ele)
        for ele in evens: arrOdd[len(arrOdd) - 1][1].append(ele)
elif qtNeedOdd == 0:
    if len(odds) % 2 == 0:
        tempNeedEven = qtNeedEven
        while tempNeedEven > 1 and len(evens) > 0:
            arrEven.append([1, [evens.pop()]])
            tempNeedEven -= 1
        while tempNeedEven > 1 and len(odds) > 2:
            arrEven.append([2, [odds.pop(), odds.pop()]])
            tempNeedEven -= 1
        arrEven.append([len(odds) + len(evens), []])
        for ele in odds: arrEven[len(arrEven) - 1][1].append(ele)
        for ele in evens: arrEven[len(arrEven) - 1][1].append(ele)
elif len(odds) >= qtNeedOdd and \
   (len(odds) - qtNeedOdd) % 2 == 0 and \
   len(evens) + ((len(odds) - qtNeedOdd) / 2) >= qtNeedEven:
    for i in range(qtNeedOdd): arrOdd.append([1, [odds.pop()]])
    tempNeedEven = qtNeedEven
    while len(odds) > 0 and tempNeedEven > 1:
        arrEven.append([2, [odds.pop(), odds.pop()]])
        tempNeedEven -= 1
    while tempNeedEven > 1:
        arrEven.append([1, [evens.pop()]])
        tempNeedEven -= 1
    if qtNeedEven == 1:
        if len(arrEven) == 0: arrEven.append([0, []])
        for ele in odds: arrEven[0][1].append(ele)
        for ele in evens: arrEven[0][1].append(ele)
        arrEven[0][0] += len(evens) + len(odds)
    else:
        arrEven.append([len(evens), evens])
        for ele in odds: arrEven[0][1].append(ele)
        arrEven[0][0] += len(odds)

if len(arrEven) == qtNeedEven and len(arrOdd) == qtNeedOdd:
    print "YES"
    for tp in arrEven:
        print tp[0],
        for ele in tp[1]: print ele,
        print
    for tp in arrOdd:
        print tp[0],
        for ele in tp[1]: print ele,
        print
else:
    print "NO"
