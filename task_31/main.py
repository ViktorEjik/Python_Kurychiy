def safeval(str, globals=globals(), locals=locals()):
    if (
        'globals().__delitem__' in str
        or 'globals().__setitem__' in str
        or 'locals().__delitem__' in str
        or 'locals().__setitem__' in str
    ):
        return
    try:
        return eval(str, globals, locals)
    except NameError:
        return str
    except Exception as E:
        return E
