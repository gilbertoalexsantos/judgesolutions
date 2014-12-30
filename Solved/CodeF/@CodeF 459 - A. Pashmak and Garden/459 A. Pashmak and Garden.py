import math
xi, yi, xf, yf = map(int,raw_input().split(" "))

def distance(ax, ay, bx, by):
    return int(math.sqrt((ax-bx)**2 + (ay-by)**2))

ax = -1
ay = -1
bx = -1
by = -1

d = distance(xi,yi,xf,yf)
can = True

## Same x
if xi == xf:
    ay = yi
    by = yf
    ax = xi + d
    bx = xf + d
    if ax > 1000:
        ax = xi - d
        bx = xf - d
## Same y
elif yi == yf:
    ax = xi
    bx = xf
    ay = yi + d
    by = yf + d
    if ay > 1000:
        ay = yi - d
else:
    ax = xi
    bx = xf
    ay = yf
    by = yi
    if(abs(xi-xf) != abs(yi-yf)):
        can = False

if ax > 1000 or ax < -1000\
    or ay > 1000 or ay < -1000\
    or bx > 1000 or bx < -1000\
    or by > 1000 or by < -1000:
        can = False


if can:
    print ax, ay, bx, by
else:
    print -1
