def joinseq(*args):
    args = list(map(iter, args))
    els = [next(x, None) for x in args]
    N = len(args)
    while any(el is not None for el in els):

        min_arg = None
        for i in range(N):
            if els[i] is None:
                continue
            if min_arg is None:
                min_arg = i
            elif els[min_arg] > els[i]:
                min_arg = i

        yield els[min_arg]
        els[min_arg] = None

        for i in range(N):
            if els[i] is None:
                x = next(args[i], None)
                els[i] = x
