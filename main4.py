import inspect
from numbers import Number


def dumper(cls):
    class new_cls(cls):
        def __str__(self):
            s = ''
            for name, par in filter(lambda x: not x[0].startswith("_"), inspect.getmembers(self)):
                if isinstance(par, Number) or isinstance(par, str):
                    s += f'{name}={par}; '
                elif inspect.ismethod(m := getattr(self, name)):
                    s += f'{name}{inspect.signature(m)}; '
                else:
                    s += f'{name}: {type(par).__name__}; '
            return s[:-2]
    return new_cls
