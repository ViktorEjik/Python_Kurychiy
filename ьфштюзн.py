from asyncio import Queue, QueueEmpty
import asyncio


class FilterQueue(Queue):
    def __init__(self, maxsize=0):
        self.head = None
        super().__init__(maxsize)

    @property
    def window(self):
        return self.head

    async def put(self, item):
        if self.empty():
            self.head = item
        await super().put(item)

    def __contains__(self, filter):
        for el in self._queue:
            if filter(el):
                return True
        return False

    def later(self):
        if self.empty():
            raise QueueEmpty
        tmp = self.get_nowait()
        self.put_nowait(tmp)
        self.head = self._queue.popleft()
        self._queue.appendleft(self.head)

    async def get(self, filter=None):
        if filter is not None and filter in self:
            while not filter(self.window):
                self.later()
        res = await super().get()
        try:
            self.head = self._queue.popleft()
            self._queue.appendleft(self.head)
        except:
            self.head = None
        return res
