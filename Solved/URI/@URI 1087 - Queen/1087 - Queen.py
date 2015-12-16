xi, yi, xf, yf = map(int, raw_input().split(" "))


def same_diagonal(xi, yi, xf, yf):
    return abs(xi-xf) == abs(yi-yf)
    

def queen_move(xi, yi, xf, yf):
    if xi == xf and yi == yf:
        return 0
    if xi == xf or yi == yf or same_diagonal(xi, yi, xf, yf):
        return 1
    return 2


while xi != 0:
    print queen_move(xi, yi, xf, yf)
    xi, yi, xf, yf = map(int, raw_input().split(" "))
