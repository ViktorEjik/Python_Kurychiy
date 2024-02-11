from math import *


class Triangle:
    def __init__(self, a, b, c):
        self.a = float(a)
        self.b = float(b)
        self.c = float(c)

        self.valid = True
        if any(map(lambda x: x <= 0, (a, b, c))):
            self.valid = False
        self.tmp = sorted([a, b, c])
        if self.tmp[0] + self.tmp[1] <= self.tmp[2]:
            self.valid = False

        p = (a + b + c) / 2
        self.square = (
            sqrt(p * (p - a) * (p - b) * (p - c))
        ) if self.valid else 0

    def __abs__(self):
        return self.square

    def __eq__(self, other):
        return all(map(isclose, self.tmp, other.tmp))

    def __gt__(self, other):
        return self.square > other.square

    def __ge__(self, other):
        return self.square >= other.square

    def __str__(self):
        return f'{self.a}:{self.b}:{self.c}'
    
    def __bool__(self):
        return self.valid
