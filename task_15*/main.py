import random


def divrandom(a, b, s, p):
    if a > b:
        a, b = b, a
    for _ in range(100):
        x = random.randrange(a, b + 1, s)
        if x % p != 0:
            return x
    return 0
