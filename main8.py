import inspect
from numbers import Number

class checker(type):
    def __init__(cls, name, parents, ns, **kwds):
        super().__init__(name, parents, ns)
        l = list(filter(lambda x: not x.startswith('_'), dir(cls)))
        for name in l:
            if (
                name in inspect.get_annotations(cls)
                and not isinstance(getattr(cls, name), inspect.get_annotations(cls)[name])
            ):
                raise TypeError
            if isinstance(cls.__dict__[name], Number):
                cls.__annotations__[name] = type(cls.__dict__[name])
        return
