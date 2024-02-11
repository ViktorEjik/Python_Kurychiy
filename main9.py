import inspect

def annodoc(fun):
    s = (
        f"{fun.__name__}:\n"
        + (f"{fun.__doc__}\n" if fun.__doc__ else '')
    )

    for atr, hint in inspect.get_annotations(fun).items():
        if isinstance(hint, str):
            if atr == 'return':
                s += f'Returns: {hint}\n'
            else:
                s += f'Variable {atr}: {hint}\n'
    fun.__doc__ = s[:-1]
    for met in filter(lambda x: inspect.isfunction(x[1]) and not x[0].startswith('_') , inspect.getmembers(fun)):
        setattr(fun, met[0], annodoc(met[1]))
    for c in filter(lambda x: inspect.isclass(x[1]) and not x[0].startswith('_') , inspect.getmembers(fun)):
        setattr(fun, c[0], annodoc(c[1]))
    return fun
