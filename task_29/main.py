from collections import Counter


class DefCounter(Counter):
    def __init__(self, collect, missing=-1):
        super().__init__(collect)
        self.missing = missing

    def __missing__(self, key):
        return self.missing

    def __abs__(self):
        mod = 0
        for elem, count in self.items():
            if count > 0:
                mod += count
        return mod
