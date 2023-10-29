from decimal import Decimal, getcontext


def PiGen():
    k = 0
    sum = 0
    while True:
        getcontext().prec = 10000
        sum += Decimal(16) ** (-k) * (
            (Decimal(4)/(Decimal(8)*Decimal(k) + Decimal(1)))
            - (Decimal(2)/(Decimal(8)*Decimal(k) + Decimal(4)))
            - (Decimal(1)/(Decimal(8)*Decimal(k) + Decimal(5)))
            - (Decimal(1)/(Decimal(8)*Decimal(k) + Decimal(6)))
        )
        yield str(sum)[k]
        k += 1
