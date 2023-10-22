SOGL = 'BCDFGHJKLMNPQRSTVWXZ'
SOGL_ALF = set(SOGL) | set(SOGL.lower())


def main():
    alf = [set(), set()]
    i = 0
    while x := input():
        alf[i % 2] |= SOGL_ALF & set(x)
        i += 1
    print('Mumbo' if len(alf[0]) > len(alf[1]) else 'Jumbo')


if __name__ == '__main__':
    main()
