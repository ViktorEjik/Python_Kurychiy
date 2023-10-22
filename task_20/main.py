import string


def evalform(formula, *args):
    arr = list()
    arg = str()
    for char in formula:
        if char in string.ascii_letters:
            arg += char
        elif arg:
            arr.append(arg)
            arg = str()
    else:
        if arg:
            arr.append(arg)

    dic = {x: y for x, y in zip(sorted(list(set(arr))), args)}
    return eval(formula, dic)
