class Tester:
    def __init__(self, fun):
        self.f = fun

    def __call__(self, suite, allowed=tuple()):
        res = 0
        for arg in suite:
            try:
                self.f(*arg)
            except tuple(allowed):
                if res != 1:
                    res = -1
            except Exception:
                res = 1
        return res
