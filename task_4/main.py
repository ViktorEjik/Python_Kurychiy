def main():
    count = 0
    n = int(input())
    a = 1
    b = int(n**(1/3))
    while a <= b:
        if a**3 + b**3 > n:
            b -= 1
        elif a**3 + b**3 < n:
            a += 1
        else:
            count += 1
            a += 1
    return count


if __name__ == '__main__':
    print(main())

