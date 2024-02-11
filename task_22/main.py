from itertools import permutations


def checkcomm(fun, *args):
    perms = permutations(args)
    ans = fun(*next(perms))
    for perm in perms:
        if ans != fun(*perm):
            return False
    return True
