from collections import deque


class Lock:
    busy = {}
    sems = {}

    def __init__(self, par):
        self.par = par
        self._lock = None

        self.sem = None

    def __str__(self):
        return str(self.par)

    @property
    def lock(self):
        if self.sem not in Lock.busy:
            for k, v in Lock.sems.items():
                if self.par in v:
                    self._lock = self.sem
                    Lock.busy[self.sem] = self.par
        elif self.par != Lock.busy[self.sem]:
            self._lock = None
        return self._lock

    @lock.setter
    def lock(self, value):
        busy = Lock.busy.items()
        for k, v in busy:
            if self.par == v:
                del Lock.busy[k]
                break
        for k, v in Lock.sems.items():
            if self.par in v:
                Lock.sems[k].remove(self.par)
                break
        self.sem = value
        try:
            Lock.sems[value].append(self.par)
        except:
            Lock.sems[value] = deque([self.par])


    @lock.deleter
    def lock(self):
        busy = Lock.busy.items()
        for k, v in busy:
            if self.par == v:
                del Lock.busy[k]
                break
        for k, v in Lock.sems.items():
            if v:
                if self.par == v[0]:
                    Lock.sems[k].popleft()

    def __del__(self):
        busy = Lock.busy.items()
        for k, v in busy:
            if self.par == v:
                del Lock.busy[k]
                break
        for k, v in Lock.sems.items():
            if self.par in v:
                Lock.sems[k].remove(self.par)

    def locked(self):
        return Lock
