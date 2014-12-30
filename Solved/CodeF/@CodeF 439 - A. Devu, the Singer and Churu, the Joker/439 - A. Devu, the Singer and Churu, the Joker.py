n, d = map(int,raw_input().split(" "))

arr = map(int,raw_input().split(" "))
arr = [i + 10 for i in arr]
arr[len(arr)-1] -= 10

qt_joke = sum(arr)

if qt_joke > d:
    print -1
else:
    ans = 0
    ans += (10 * (len(arr) - 1)) / 5
    ans += (d - qt_joke) / 5
    print ans
