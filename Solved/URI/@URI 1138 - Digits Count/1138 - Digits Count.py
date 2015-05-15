def digit_count(number, digit):
    ret = 0

    flag = number
    factor = 1
    rest = number % factor

    while flag:
        my_digit = flag % 10
        flag /= 10

        offset_zero = (digit == 0 and flag and factor != 1)

        ret += (flag - offset_zero) * factor

        if digit != 0 or (digit == 0 and flag):
            if my_digit == digit:
                ret += rest + 1
            elif my_digit > digit:
                ret += factor

        factor *= 10
        rest = number % factor

    return ret

print digit_count(4446, 0)
