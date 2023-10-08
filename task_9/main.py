def sheff(A, B):
    if A and B:
        return False
    if not A and not B:
        return True
    if A:
        return A
    return B
