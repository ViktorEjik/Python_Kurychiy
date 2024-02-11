class Geom:
    def __init__(self, base, denominator):
        self.base = base
        self.denominator = denominator

    @staticmethod
    def gen(base, denominator):

        mul = base
        yield mul
        while True:
            mul *= denominator
            yield mul

    def __getitem__(self, item):
        g = self.gen(self.base, self.denominator)
        if isinstance(item, int):
            yield from [self.base*self.denominator**(item-1)]
        elif isinstance(item, tuple):
            if len(item) == 3:
                yield from [next(g) for _ in range(item[2])][item[0]:]
            elif len(item) == 2 and isinstance(item[0], type(...)):
                yield from [next(g) for _ in range(item[1])]
            else:
                for i in range(item[0]):
                    next(g)
                yield from g

        elif isinstance(item, slice):
            start = item.start if item.start else 0
            stop = item.stop if item.stop else 0
            g = self.gen(type(self.base)(self.base*self.denominator**(min(start, stop))), self.denominator)
            if item.start is None and item.stop is None:
                yield from self.__iter__()
            if start > stop:
                yield from [next(g) for _ in range(start-stop + 1)][::item.step]
            else:
                yield from [next(g) for _ in range(stop - start)][::item.step]
        else:
            yield from self.__iter__()

    def __iter__(self):
        g = self.gen(self.base, self.denominator)
        yield from g
