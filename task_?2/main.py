def is_empty(self):
    return all(
        map(
            lambda x: True if x[0].startswith('__') else x[1],
            self.__dict__.items()
        )
    )


class empty(type):
    def __new__(cls, name, bases, dct):
        dct['__bool__'] = lambda self: is_empty(self)
        return super().__new__(cls, name, bases, dct)
