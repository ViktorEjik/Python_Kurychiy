class Smile:
    def __init__(self, mod):
        self.module = mod

    def __abs__(self):
        return abs(self.module)

    def __neg__(self):
        return Smile(-self.module)

    def __mul__(self, other: int):
        return Smile(self.module * other)

    def __add__(self, other):
        return Smile(self.module + other.module)

    def __sub__(self, other):
        return Smile(self.module - other.module)

    def __str__(self):
        abs = self.__abs__()
        if abs == 0:
            return ''
        elif abs == 1:
            return (
                '/1\\\n'
                + '|"|\n'
                + '\\-/'
            )

        n, m = (3 + (abs - 1)*2), 3 + (abs - 1)
        img = [[' ' for _ in range(n)] for _ in range(m)]
        for i in range(1, n-1):
            img[0][i] = '-'
            img[-1][i] = '-'
        for i in range(1, m-1):
            img[i][0] = '|'
            img[i][-1] = '|'

        pad = abs // 4
        img[pad+1][pad+1] = 'O'
        img[pad+1][-pad-2] = 'O'
        for i in range(pad+2, n-pad-2):
            img[-pad-2][i] = '-'

        if self.module < 0:
            img = img[::-1]

        img[0][0] = '/'
        img[0][-1] = "\\"
        img[-1][0] = '\\'
        img[-1][-1] = '/'
        abs = str(abs)
        for i, n in zip(range(len(abs)), abs):
            img[0][i+1] = n
        strs = list()
        for i in range(m):
            strs.append(''.join(img[i]))
        return '\n'.join(strs)
