from abc import ABCMeta, abstractmethod
from typing import Any, TypeVar, MutableSequence

class Comparable(metaclass=ABCMeta):
    @abstractmethod
    def __lt__(self, other: Any) -> bool: ...

Sortable = MutableSequence[Comparable]

def bubble(sequence: Sortable) -> Sortable:
    N = len(sequence)
    for i in range(N-1):
        for j in range(N-i-1):
            if sequence[j] > sequence[j+1]:
                sequence[j], sequence[j+1] = sequence[j+1], sequence[j]
    return sequence
