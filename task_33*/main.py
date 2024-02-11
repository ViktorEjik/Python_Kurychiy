from itertools import product

_c = product('abcd', repeat=4)
class Struct:
    __slots__ = []

    def __getattribute__(self, item):
        if len(item) != 4:
            raise AttributeError
        if tuple(item) in _c:
            return item
        print(list(_c))
        raise AttributeError


from itertools import product
from collections import Counter

lst = [Struct() for i in range(1000000)]
FIELDS = ["".join(q) for q in product(*(["abcd"] * 4))]
res = Counter(getattr(l, FIELDS[i % len(FIELDS)]) for i, l in enumerate(lst))
print(sorted(set(res.values())))
