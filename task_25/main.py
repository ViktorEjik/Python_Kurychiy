class Shared:
    objects = 0
    live = 0
    total = 0

    def __init__(self):
        Shared.objects += 1
        Shared.live += 1
        self.local = 0

    def __invert__(self):
        self.local += 1
        Shared.total += 1
        return self.local

    def __del__(self):
        Shared.live -= 1

    def __str__(self):
        return f'|{Shared.objects}/{Shared.live}/{Shared.total}/{self.local}|'
