from inspect import signature


def DefArgs(*const):
    def decor(fun):
        sign = list(filter(lambda x: x != '', str(signature(fun))[1:-1].split(', ')))
        if len(const) < len(sign):
            raise TypeError
        consts = const[:len(sign)]

        def newfun(*args):
            if len(args) > len(sign):
                raise TypeError
            if any(not isinstance(a, type(c)) for c, a in zip(consts, args)):
                raise TypeError
            args += consts[len(args):]
            return fun(*args)
        return newfun
    return decor
