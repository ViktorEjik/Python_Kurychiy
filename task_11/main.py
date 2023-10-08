def compose(f, g):
    def h(*args):
        return f(g(*args), g(*args[::-1]))
    return h
