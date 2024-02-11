from collections import UserString


class SubString(UserString):
    def __init__(self, str):
        super().__init__(str)

    def __sub__(self, other):
        from collections import Counter
        dict_self = Counter(self)
        dict_other = Counter(other)
        s = str()
        for c in self:
            if c in dict_other and dict_other[c] > 0:
                dict_other[c] -= 1
                dict_self[c] -= 1
            else:
                s += c if dict_self[c] > 0 else ''
                dict_self[c] -= 1
        return SubString(s)


del UserString
