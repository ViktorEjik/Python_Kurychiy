import time
import math


def all_products(n, dels):
    i = dels[-1]
    while i < math.sqrt(n) + 1:
        if n % i == 0:
            dels.append(i)
            all_products(n//i, dels)
        i += 1

    if dels[-1] <= n:
        print(*dels, n, sep='*')
    dels.pop()
    return


def main():
    n = int(input())
    i = 2
    while i < math.sqrt(n) + 1:
        if n % i == 0:
            all_products(n//i, [i])
        i += 1
    print(n)


if __name__ == '__main__':
    main()

