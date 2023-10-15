import decimal
from decimal import Decimal


def det3(r0, r1, r2):
    def det2(r0, r1):
        return r0[0] * r1[1] - r0[1] * r1[0]

    return (r0[0] * det2(r1[1:], r2[1:])
            - r0[1] * det2(r1[::2], r2[::2])
            + r0[2] * det2(r1[:2], r2[:2]))


def main():
    x1, y1, x2, y2, x3, y3 = map(Decimal, input().split(','))
    decimal.getcontext().prec = 200
    res = Decimal(1/2) * abs(det3((1, 1, 1), (x1, x2, x3), (y1, y2, y3)))
    dec = len(str(res).split('.')[1]) - 1
    print(round(res, dec))


if __name__ == '__main__':
    main()
