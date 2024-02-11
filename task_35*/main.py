def Record(string: str, **kwargs):
    atrs = string.split()

    def newclass(cls):
        print('cls: ', cls.__slots__)
        print('kwargs: ', kwargs)
        print('args', atrs)
        class NewClass:
            __slots__ = sorted(list(set(cls.__slots__ + atrs)))

            def __iter__(self):
                yield from filter(lambda x: x[0] != '_', dir(self))

            def __str__(self):
                s = ''
                for atr in self:
                    if 'fget' in dir(getattr(type(self), atr)):
                        s += f'{atr}:{self.__getattribute__(atr)}|'
                        continue

                    try:
                        s += f'{atr}={self.__getattribute__(atr)}|'
                    except:
                        s += f'{atr}|'
                return s[:-1]

        for key in kwargs:
            def get(self, atr=kwargs[key]):
                return atr

            setattr(NewClass, key, property(get))

        return NewClass
    return newclass


import string
#@Record(" ".join(string.ascii_lowercase), **dict(zip(string.ascii_uppercase, string.ascii_uppercase)))
class C:
    __slots__ = [string.ascii_lowercase[i: i + 2] for i in range(len(string.ascii_lowercase))]
    locals().update({f.upper(): i for i, f in enumerate(__slots__)})
    def __iter__(self):
        yield from self.__slots__

c = C()
print(",".join(c.__slots__))
print(",".join(c))
print(c)
