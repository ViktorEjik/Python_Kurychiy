import inspect
import sys
import types


def whocall(depth):
    try:
        frame = sys._getframe(depth)
    except :
        return ('<UNIVERSE>', '')
    fn = types.FunctionType(
        frame.f_code, frame.f_globals, frame.f_code.co_name,
    )
    stack = inspect.stack()
    sign = str(inspect.signature(fn))[1:-1].split()
    for i in range(len(sign)):
        sign[i] = ''.join(filter(lambda x: x not in '*/,', sign[i]))
    return (stack[depth].function, ' '.join(filter(lambda x: bool(x), sign)))
