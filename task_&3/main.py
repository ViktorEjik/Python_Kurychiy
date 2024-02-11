from inspect import get_annotations


def fancy_print(self):
    ans = []
    for el in get_annotations(self.__class__).keys():
        try:
            ans.append(f'{el}={getattr(self, str(el))}')
        except Exception as e:
            pass
    return ' '.join(ans)


class positioned(type):

    def __new__(cls, name, bases, dct):
        def __init__(self, *args, **kwargs):
            self.__class__.__match_args__ = tuple([*get_annotations(self.__class__).keys()])
            annot = list(get_annotations(self.__class__).keys())

            for item in filter(lambda x: x[0] in annot, kwargs.items()):
                setattr(self, item[0], item[1])

            k = 0
            for i, el in enumerate(args):
                while annot[k] in kwargs:
                    k += 1
                    if k == len(annot):
                        break
                if k == len(annot):
                    break
                setattr(self, annot[k], el)
                k += 1
                if k == len(annot):
                    break

        dct['__str__'] = lambda self: fancy_print(self)
        dct['__init__'] = __init__
        return super().__new__(cls, name, bases, dct)
